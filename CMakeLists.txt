cmake_minimum_required(VERSION 3.13)

project(fallout2-re LANGUAGES C)

add_executable(fallout2-re WIN32
    "src/actions.c"
    "src/actions.h"
    "src/animation.c"
    "src/animation.h"
    "src/args.c"
    "src/args.h"
    "src/art.c"
    "src/art.h"
    "src/audio_file.c"
    "src/audio_file.h"
    "src/audio.c"
    "src/audio.h"
    "src/automap.c"
    "src/automap.h"
    "src/autorun.c"
    "src/autorun.h"
    "src/cache.c"
    "src/cache.h"
    "src/character_editor.c"
    "src/character_editor.h"
    "src/character_selector.c"
    "src/character_selector.h"
    "src/color.c"
    "src/color.h"
    "src/combat_ai_defs.h"
    "src/combat_ai.c"
    "src/combat_ai.h"
    "src/combat_defs.h"
    "src/combat.c"
    "src/combat.h"
    "src/config.c"
    "src/config.h"
    "src/core.c"
    "src/core.h"
    "src/credits.c"
    "src/credits.h"
    "src/critter.c"
    "src/critter.h"
    "src/cycle.c"
    "src/cycle.h"
    "src/datafile.c"
    "src/datafile.h"
    "src/db.c"
    "src/db.h"
    "src/dbox.c"
    "src/dbox.h"
    "src/debug.c"
    "src/debug.h"
    "src/dfile.c"
    "src/dfile.h"
    "src/dialog.c"
    "src/dialog.h"
    "src/dictionary.c"
    "src/dictionary.h"
    "src/dinput.c"
    "src/dinput.h"
    "src/display_monitor.c"
    "src/display_monitor.h"
    "src/draw.c"
    "src/draw.h"
    "src/electronic_registration.c"
    "src/electronic_registration.h"
    "src/elevator.c"
    "src/elevator.h"
    "src/endgame.c"
    "src/endgame.h"
    "src/export.c"
    "src/export.h"
    "src/file_find.c"
    "src/file_find.h"
    "src/file_utils.c"
    "src/file_utils.h"
    "src/font_manager.c"
    "src/font_manager.h"
    "src/game_config.c"
    "src/game_config.h"
    "src/game_dialog.c"
    "src/game_dialog.h"
    "src/game_memory.c"
    "src/game_memory.h"
    "src/game_mouse.c"
    "src/game_mouse.h"
    "src/game_movie.c"
    "src/game_movie.h"
    "src/game_palette.c"
    "src/game_palette.h"
    "src/game_sound.c"
    "src/game_sound.h"
    "src/game_vars.h"
    "src/game.c"
    "src/game.h"
    "src/geometry.c"
    "src/geometry.h"
    "src/graph_lib.c"
    "src/graph_lib.h"
    "src/grayscale.c"
    "src/grayscale.h"
    "src/heap.c"
    "src/heap.h"
    "src/interface.c"
    "src/interface.h"
    "src/interpreter_extra.c"
    "src/interpreter_extra.h"
    "src/interpreter_lib.c"
    "src/interpreter_lib.h"
    "src/interpreter.c"
    "src/interpreter.h"
    "src/inventory.c"
    "src/inventory.h"
    "src/item.c"
    "src/item.h"
    "src/light.c"
    "src/light.h"
    "src/lips.c"
    "src/lips.h"
    "src/loadsave.c"
    "src/loadsave.h"
    "src/main.c"
    "src/main.h"
    "src/map_defs.h"
    "src/map.c"
    "src/map.h"
    "src/memory_defs.h"
    "src/memory_manager.c"
    "src/memory_manager.h"
    "src/memory.c"
    "src/memory.h"
    "src/message.c"
    "src/message.h"
    "src/mmx.c"
    "src/mmx.h"
    "src/mouse_manager.c"
    "src/mouse_manager.h"
    "src/movie_effect.c"
    "src/movie_effect.h"
    "src/movie_lib.c"
    "src/movie_lib.h"
    "src/movie.c"
    "src/movie.h"
    "src/nevs.c"
    "src/nevs.h"
    "src/obj_types.h"
    "src/object.c"
    "src/object.h"
    "src/options.c"
    "src/options.h"
    "src/palette.c"
    "src/palette.h"
    "src/party_member.c"
    "src/party_member.h"
    "src/perk_defs.h"
    "src/perk.c"
    "src/perk.h"
    "src/pipboy.c"
    "src/pipboy.h"
    "src/proto_instance.c"
    "src/proto_instance.h"
    "src/proto_types.h"
    "src/proto.c"
    "src/proto.h"
    "src/queue.c"
    "src/queue.h"
    "src/random.c"
    "src/random.h"
    "src/reaction.c"
    "src/reaction.h"
    "src/region.c"
    "src/region.h"
    "src/scripts.c"
    "src/scripts.h"
    "src/select_file_list.c"
    "src/select_file_list.h"
    "src/selfrun.c"
    "src/selfrun.h"
    "src/skill_defs.h"
    "src/skill.c"
    "src/skill.h"
    "src/skilldex.c"
    "src/skilldex.h"
    "src/sound_decoder.c"
    "src/sound_decoder.h"
    "src/sound_effects_cache.c"
    "src/sound_effects_cache.h"
    "src/sound_effects_list.c"
    "src/sound_effects_list.h"
    "src/sound.c"
    "src/sound.h"
    "src/stat_defs.h"
    "src/stat.c"
    "src/stat.h"
    "src/string_parsers.c"
    "src/string_parsers.h"
    "src/text_font.c"
    "src/text_font.h"
    "src/text_object.c"
    "src/text_object.h"
    "src/tile.c"
    "src/tile.h"
    "src/trait_defs.h"
    "src/trait.c"
    "src/trait.h"
    "src/trap.c"
    "src/trap.h"
    "src/version.c"
    "src/version.h"
    "src/widget.c"
    "src/widget.h"
    "src/win32.c"
    "src/win32.h"
    "src/window_manager_private.c"
    "src/window_manager_private.h"
    "src/window_manager.c"
    "src/window_manager.h"
    "src/window.c"
    "src/window.h"
    "src/word_wrap.c"
    "src/word_wrap.h"
    "src/world_map.c"
    "src/world_map.h"
    "src/xfile.c"
    "src/xfile.h"
)

target_compile_definitions(fallout2-re PUBLIC
    _CRT_SECURE_NO_WARNINGS
    _CRT_NONSTDC_NO_WARNINGS
)

target_link_libraries(fallout2-re
    winmm
)

add_subdirectory("third_party/fpattern")
add_subdirectory("third_party/zlib")
