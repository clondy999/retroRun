#include "overrides.h"

static const struct core_override_option mgba_core_option_overrides[] = {
	{
      .key = "mgba_force_gbp",
      .desc = "Game Boy Player Rumble (Restart)",
      .info = "Enabling this will allow compatible games with the Game Boy Player boot logo to make the controller rumble. Due to how Nintendo decided this feature should work, it may cause glitches such as flickering or lag in some of these games.",
 	  .default_value = "ON",
	  .options = {
         { "OFF", "disabled" },
         { "ON",  "enabled" },
         { NULL, NULL },
      }
   },
	{ NULL }
};

me_bind_action mgba_ctrl_actions[] =
{
	{ "UP       ",  1 << RETRO_DEVICE_ID_JOYPAD_UP},
	{ "DOWN     ",  1 << RETRO_DEVICE_ID_JOYPAD_DOWN },
	{ "LEFT     ",  1 << RETRO_DEVICE_ID_JOYPAD_LEFT },
	{ "RIGHT    ",  1 << RETRO_DEVICE_ID_JOYPAD_RIGHT },
	{ "A BUTTON ",  1 << RETRO_DEVICE_ID_JOYPAD_A },
	{ "B BUTTON ",  1 << RETRO_DEVICE_ID_JOYPAD_B },
	{ "A TURBO  ",  1 << RETRO_DEVICE_ID_JOYPAD_X },
	{ "B TURBO  ",  1 << RETRO_DEVICE_ID_JOYPAD_Y },
	{ "START    ",  1 << RETRO_DEVICE_ID_JOYPAD_START },
	{ "SELECT   ",  1 << RETRO_DEVICE_ID_JOYPAD_SELECT },
	{ "L BUTTON ",  1 << RETRO_DEVICE_ID_JOYPAD_L },
	{ "R BUTTON ",  1 << RETRO_DEVICE_ID_JOYPAD_R },
	/* { "FAST FWD ",  1 << RETRO_DEVICE_ID_JOYPAD_R2 }, */
	{ NULL,       0 }
};

const struct core_override_fast_forward mgba_fast_forward = {
	.type_key = "mgba_frameskip",
	.interval_key = "mgba_frameskip_interval"
};

#define gpsp_overrides {                                \
	.core_name = "mgba",                            \
	.fast_forward = &mgba_fast_forward,             \
	.actions = mgba_ctrl_actions,                   \
	.action_size = array_size(mgba_ctrl_actions),   \
	.options = mgba_core_option_overrides           \
}
