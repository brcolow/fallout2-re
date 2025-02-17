#include "export.h"

#include "interpreter_lib.h"
#include "memory_manager.h"

// 0x570C00
ExternalProcedure gExternalProcedures[1013];

// 0x57BA1C
ExternalVariable gExternalVariables[1013];

// NOTE: Inlined.
//
// 0x440F10
unsigned int _hashName(const char* identifier)
{
    unsigned int v1 = 0;
    const char* pch = identifier;
    while (*pch != '\0') {
        int ch = *pch & 0xFF;
        v1 += (tolower(ch) & 0xFF) + (v1 * 8) + (v1 >> 29);
        pch++;
    }

    v1 = v1 % 1013;
    return v1;
}

// 0x440F58
ExternalProcedure* externalProcedureFind(const char* identifier)
{
    // NOTE: Uninline.
    unsigned int v1 = _hashName(identifier);
    unsigned int v2 = v1;

    ExternalProcedure* externalProcedure = &(gExternalProcedures[v1]);
    if (externalProcedure->program != NULL) {
        if (stricmp(externalProcedure->name, identifier) == 0) {
            return externalProcedure;
        }
    }

    do {
        v1 += 7;
        if (v1 >= 1013) {
            v1 -= 1013;
        }

        externalProcedure = &(gExternalProcedures[v1]);
        if (externalProcedure->program != NULL) {
            if (stricmp(externalProcedure->name, identifier) == 0) {
                return externalProcedure;
            }
        }
    } while (v1 != v2);

    return NULL;
}

// 0x441018
ExternalProcedure* externalProcedureAdd(const char* identifier)
{
    // NOTE: Uninline.
    unsigned int v1 = _hashName(identifier);
    unsigned int a2 = v1;

    ExternalProcedure* externalProcedure = &(gExternalProcedures[v1]);
    if (externalProcedure->name[0] == '\0') {
        return externalProcedure;
    }

    do {
        v1 += 7;
        if (v1 >= 1013) {
            v1 -= 1013;
        }

        externalProcedure = &(gExternalProcedures[v1]);
        if (externalProcedure->name[0] == '\0') {
            return externalProcedure;
        }
    } while (v1 != a2);

    return NULL;
}

// 0x4410AC
ExternalVariable* externalVariableFind(const char* identifier)
{
    // NOTE: Uninline.
    unsigned int v1 = _hashName(identifier);
    unsigned int v2 = v1;

    ExternalVariable* exportedVariable = &(gExternalVariables[v1]);
    if (stricmp(exportedVariable->name, identifier) == 0) {
        return exportedVariable;
    }

    do {
        exportedVariable = &(gExternalVariables[v1]);
        if (exportedVariable->name[0] == '\0') {
            break;
        }

        v1 += 7;
        if (v1 >= 1013) {
            v1 -= 1013;
        }

        exportedVariable = &(gExternalVariables[v1]);
        if (stricmp(exportedVariable->name, identifier) == 0) {
            return exportedVariable;
        }
    } while (v1 != v2);

    return NULL;
}

// 0x44118C
ExternalVariable* externalVariableAdd(const char* identifier)
{
    // NOTE: Uninline.
    unsigned int v1 = _hashName(identifier);
    unsigned int v2 = v1;

    ExternalVariable* exportedVariable = &(gExternalVariables[v1]);
    if (exportedVariable->name[0] == '\0') {
        return exportedVariable;
    }

    do {
        v1 += 7;
        if (v1 >= 1013) {
            v1 -= 1013;
        }

        exportedVariable = &(gExternalVariables[v1]);
        if (exportedVariable->name[0] == '\0') {
            return exportedVariable;
        }
    } while (v1 != v2);

    return NULL;
}

// 0x44127C
int externalVariableSetValue(Program* program, const char* name, opcode_t opcode, int data)
{
    ExternalVariable* exportedVariable = externalVariableFind(name);
    if (exportedVariable == NULL) {
        return 1;
    }

    if ((exportedVariable->type & 0xF7FF) == VALUE_TYPE_STRING) {
        internal_free_safe(exportedVariable->stringValue, __FILE__, __LINE__); // "..\\int\\EXPORT.C", 169
    }

    if ((opcode & 0xF7FF) == VALUE_TYPE_STRING) {
        if (program != NULL) {
            const char* stringValue = programGetString(program, opcode, data);
            exportedVariable->type = VALUE_TYPE_DYNAMIC_STRING;

            exportedVariable->stringValue = internal_malloc_safe(strlen(stringValue) + 1, __FILE__, __LINE__); // "..\\int\\EXPORT.C", 175
            strcpy(exportedVariable->stringValue, stringValue);
        }
    } else {
        exportedVariable->value = data;
        exportedVariable->type = opcode;
    }

    return 0;
}

// 0x4413D4
int externalVariableGetValue(Program* program, const char* name, opcode_t* opcodePtr, int* dataPtr)
{
    ExternalVariable* exportedVariable = externalVariableFind(name);
    if (exportedVariable == NULL) {
        return 1;
    }

    *opcodePtr = exportedVariable->type;

    if ((exportedVariable->type & 0xF7FF) == VALUE_TYPE_STRING) {
        *dataPtr = programPushString(program, exportedVariable->stringValue);
    } else {
        *dataPtr = exportedVariable->value;
    }

    return 0;
}

// 0x4414B8
int externalVariableCreate(Program* program, const char* identifier)
{
    const char* programName = program->name;
    ExternalVariable* exportedVariable = externalVariableFind(identifier);

    if (exportedVariable != NULL) {
        if (stricmp(exportedVariable->programName, programName) != 0) {
            return 1;
        }

        if ((exportedVariable->type & 0xF7FF) == VALUE_TYPE_STRING) {
            internal_free_safe(exportedVariable->stringValue, __FILE__, __LINE__); // "..\\int\\EXPORT.C", 234
        }
    } else {
        exportedVariable = externalVariableAdd(identifier);
        if (exportedVariable == NULL) {
            return 1;
        }

        strncpy(exportedVariable->name, identifier, 31);

        exportedVariable->programName = internal_malloc_safe(strlen(programName) + 1, __FILE__, __LINE__); // // "..\\int\\EXPORT.C", 243
        strcpy(exportedVariable->programName, programName);
    }

    exportedVariable->type = VALUE_TYPE_INT;
    exportedVariable->value = 0;

    return 0;
}

// 0x4414FC
void _removeProgramReferences(Program* program)
{
    for (int index = 0; index < 1013; index++) {
        ExternalProcedure* externalProcedure = &(gExternalProcedures[index]);
        if (externalProcedure->program == program) {
            externalProcedure->name[0] = '\0';
            externalProcedure->program = NULL;
        }
    }
}

// 0x44152C
void _initExport()
{
    _interpretRegisterProgramDeleteCallback(_removeProgramReferences);
}

// 0x441538
void externalVariablesClear()
{
    for (int index = 0; index < 1013; index++) {
        ExternalVariable* exportedVariable = &(gExternalVariables[index]);

        if (exportedVariable->name[0] != '\0') {
            internal_free_safe(exportedVariable->programName, __FILE__, __LINE__); // ..\\int\\EXPORT.C, 274
        }

        if (exportedVariable->type == VALUE_TYPE_DYNAMIC_STRING) {
            internal_free_safe(exportedVariable->stringValue, __FILE__, __LINE__); // ..\\int\\EXPORT.C, 276
        }
    }
}

// 0x44158C
Program* externalProcedureGetProgram(const char* identifier, int* addressPtr, int* argumentCountPtr)
{
    ExternalProcedure* externalProcedure = externalProcedureFind(identifier);
    if (externalProcedure == NULL) {
        return NULL;
    }

    if (externalProcedure->program == NULL) {
        return NULL;
    }

    *addressPtr = externalProcedure->address;
    *argumentCountPtr = externalProcedure->argumentCount;

    return externalProcedure->program;
}

// 0x4415B0
int externalProcedureCreate(Program* program, const char* identifier, int address, int argumentCount)
{
    ExternalProcedure* externalProcedure = externalProcedureFind(identifier);
    if (externalProcedure != NULL) {
        if (program != externalProcedure->program) {
            return 1;
        }
    } else {
        externalProcedure = externalProcedureAdd(identifier);
        if (externalProcedure == NULL) {
            return 1;
        }

        strncpy(externalProcedure->name, identifier, 31);
    }

    externalProcedure->argumentCount = argumentCount;
    externalProcedure->address = address;
    externalProcedure->program = program;

    return 0;
}

// 0x441824
void _exportClearAllVariables()
{
    for (int index = 0; index < 1013; index++) {
        ExternalVariable* exportedVariable = &(gExternalVariables[index]);
        if (exportedVariable->name[0] != '\0') {
            if ((exportedVariable->type & 0xF7FF) == VALUE_TYPE_STRING) {
                if (exportedVariable->stringValue != NULL) {
                    internal_free_safe(exportedVariable->stringValue, __FILE__, __LINE__); // "..\\int\\EXPORT.C", 387
                }
            }

            if (exportedVariable->programName != NULL) {
                internal_free_safe(exportedVariable->programName, __FILE__, __LINE__); // "..\\int\\EXPORT.C", 393
                exportedVariable->programName = NULL;
            }

            exportedVariable->name[0] = '\0';
            exportedVariable->type = 0;
        }
    }
}
