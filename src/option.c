/*
 * File: options.c
 * Purpose: Options table and definitions.
 *
 * Copyright (c) 1997 Ben Harrison
 *
 * This work is free software; you can redistribute it and/or modify it
 * under the terms of either:
 *
 * a) the GNU General Public License as published by the Free Software
 *    Foundation, version 2, or
 *
 * b) the "Angband licence":
 *    This software may be copied and distributed for educational, research,
 *    and not for profit purposes provided that this copyright and statement
 *    are included in all such copies.  Other copyrights may also apply.
 */
#include "angband.h"
#include "option.h"

/*
 * Option screen interface
 */
const int option_page[OPT_PAGE_MAX][OPT_PAGE_PER] =
{
	/* Interface */
	{
		OPT_rogue_like_commands,
		OPT_use_old_target,
		OPT_pickup_always,
		OPT_pickup_inven,
		OPT_center_player,
		OPT_show_flavors,
		OPT_mouse_movement,
		OPT_mouse_buttons,
		OPT_use_sound,
		OPT_show_damage,
		OPT_view_yellow_light,
		OPT_animate_flicker,
		OPT_solid_walls,
		OPT_hybrid_walls,
		OPT_NONE,
		OPT_NONE,
	},


	/* Warning */
	{
		OPT_hp_changes_color,
		OPT_purple_uniques,
		OPT_disturb_near,
		OPT_auto_more,
		OPT_notify_recharge,
		OPT_NONE,
		OPT_NONE,
		OPT_NONE,
		OPT_NONE,
		OPT_NONE,
		OPT_NONE,
		OPT_NONE,
		OPT_NONE,
	},

	/* Birth/Difficulty */
	{
		OPT_birth_randarts,
		OPT_birth_keep_randarts,
		OPT_birth_ai_learn,
		OPT_birth_force_descend,
		OPT_birth_no_recall,
		OPT_birth_small_range,
		OPT_birth_no_artifacts,
		OPT_birth_no_stacking,
		OPT_birth_no_preserve,
		OPT_birth_no_stairs,
		OPT_birth_no_feelings,
		OPT_birth_no_selling,
		OPT_NONE,
		OPT_NONE,
		OPT_NONE,
		OPT_NONE,
	},

	/* Cheat */
	{
		OPT_cheat_hear,
		OPT_cheat_room,
		OPT_cheat_xtra,
		OPT_cheat_know,
		OPT_cheat_live,
		OPT_NONE,
		OPT_NONE,
		OPT_NONE,
		OPT_NONE,
		OPT_NONE,
		OPT_NONE,
		OPT_NONE,
		OPT_NONE,
		OPT_NONE,
		OPT_NONE,
		OPT_NONE,
	}
};


struct option
{
	const char *name;
	const char *description;
	bool normal;
};

static const struct option options[OPT_MAX] =
{
{ "rogue_like_commands", "Use the roguelike command keyset",            FALSE }, /* 0 */
{ "use_sound",           "Use sound",                                   FALSE }, /* 1 */
{ "show_damage",         "Show damage player deals to monsters",        FALSE }, /* 2 */
{ "use_old_target",      "Use old target by default",                   FALSE }, /* 3 */
{ "pickup_always",       "Always pickup items",                         FALSE }, /* 4 */
{ "pickup_inven",        "Always pickup items matching inventory",      TRUE },  /* 5 */
{ "show_flavors",        "Show flavors in object descriptions",         FALSE }, /* 6 */
{ NULL,                  NULL,                                          FALSE }, /* 7 */
{ "disturb_near",        "Disturb whenever viewable monster moves",     TRUE },  /* 8 */
{ NULL,                  NULL,                                          FALSE }, /* 9 */
{ NULL,                  NULL,                                          FALSE }, /* 10 */
{ "solid_walls",         "Show walls as solid blocks",                  FALSE }, /* 11 */
{ "hybrid_walls",        "Show walls with shaded background",           FALSE }, /* 12 */
{ "view_yellow_light",   "Color: Illuminate torchlight in yellow",      FALSE }, /* 13 */
{ NULL,                  NULL,                                          FALSE }, /* 14 */
{ "animate_flicker",     "Color: Shimmer multi-colored things",         FALSE }, /* 15 */
{ "center_player",       "Center map continuously",                     FALSE }, /* 16 */
{ "purple_uniques",      "Color: Show unique monsters in purple",       FALSE }, /* 17 */
{ NULL,                  NULL,                                          FALSE }, /* 18 */
{ "auto_more",           "Automatically clear '-more-' prompts",        FALSE }, /* 19 */
{ "hp_changes_color",    "Color: Player color indicates % hit points",  TRUE },  /* 20 */
{ "mouse_movement",      "Allow mouse clicks to move the player",       TRUE },  /* 21 */
{ "mouse_buttons",       "Show mouse status line buttons",              FALSE }, /* 22 */
{ "notify_recharge",     "Notify on object recharge",                   FALSE }, /* 23 */
{ NULL,                  NULL,                                          FALSE }, /* 24 */
{ NULL,                  NULL,                                          FALSE }, /* 25 */
{ NULL,                  NULL,                                          FALSE }, /* 26 */
{ NULL,                  NULL,                                          FALSE }, /* 27 */
{ NULL,                  NULL,                                          FALSE }, /* 28 */
{ NULL,                  NULL,                                          FALSE }, /* 29 */
{ NULL,                  NULL,                                          FALSE }, /* 30 */
{ "cheat_hear",          "Cheat: Peek into monster creation",           FALSE }, /* 31 */
{ "cheat_room",          "Cheat: Peek into dungeon creation",           FALSE }, /* 32 */
{ "cheat_xtra",          "Cheat: Peek into something else",             FALSE }, /* 33 */
{ "cheat_know",          "Cheat: Know complete monster info",           FALSE }, /* 34 */
{ "cheat_live",          "Cheat: Allow player to avoid death",          FALSE }, /* 35 */
{ NULL,                  NULL,                                          FALSE }, /* 36 */
{ NULL,                  NULL,                                          FALSE }, /* 37 */
{ NULL,                  NULL,                                          FALSE }, /* 38 */
{ NULL,                  NULL,                                          FALSE }, /* 39 */
{ NULL,                  NULL,                                          FALSE }, /* 40 */
{ "score_hear",          "Score: Peek into monster creation",           FALSE }, /* 41 */
{ "score_room",          "Score: Peek into dungeon creation",           FALSE }, /* 42 */
{ "score_xtra",          "Score: Peek into something else",             FALSE }, /* 43 */
{ "score_know",          "Score: Know complete monster info",           FALSE }, /* 44 */
{ "score_live",          "Score: Allow player to avoid death",          FALSE }, /* 45 */
{ NULL,                  NULL,                                          FALSE }, /* 46 */
{ NULL,                  NULL,                                          FALSE }, /* 47 */
{ NULL,                  NULL,                                          FALSE }, /* 48 */
{ NULL,                  NULL,                                          FALSE }, /* 49 */
{ NULL,                  NULL,                                          FALSE }, /* 50 */
{ "birth_randarts",      "Randomise the artifacts (except a very few)", FALSE }, /* 51 */
{ "birth_no_recall",     "Word of Recall has no effect",                FALSE }, /* 52 */
{ "birth_small_range",   "Halve view and spell distances",              FALSE }, /* 53 */
{ "birth_no_artifacts",  "Restrict creation of artifacts",              FALSE }, /* 54 */
{ "birth_no_stacking",   "Don't stack objects on the floor",            FALSE }, /* 55 */
{ "birth_no_preserve",   "Lose artifacts when leaving level",           FALSE }, /* 56 */
{ "birth_no_stairs",     "Don't generate connected stairs",             FALSE }, /* 57 */
{ "birth_no_feelings",   "Don't show level feelings",                   FALSE }, /* 58 */
{ "birth_no_selling",    "Items always sell for 0 gold",                TRUE }, /* 59 */
{ "birth_keep_randarts", "Use previous set of randarts",                TRUE },  /* 60 */
{ NULL,                  NULL,                                          FALSE }, /* 61 */
{ NULL,                  NULL,                                          FALSE }, /* 62 */
{ "birth_ai_learn",      "Monsters learn from their mistakes",          FALSE }, /* 63 */
{ NULL,                  NULL,                                          FALSE }, /* 64 */
{ "birth_force_descend", "Force player descent",                        FALSE }, /* 65 */
{ NULL,                  NULL,                                          FALSE }, /* 66 */
{ NULL,                  NULL,                                          FALSE }, /* 67 */
{ NULL,                  NULL,                                          FALSE }, /* 68 */
{ NULL,                  NULL,                                          FALSE }, /* 69 */
};


/* Accessor functions */
const char *option_name(int opt)
{
	if (opt >= OPT_MAX) return NULL;
	return options[opt].name;
}

const char *option_desc(int opt)
{
	if (opt >= OPT_MAX) return NULL;
	return options[opt].description;
}

#if 0 /* unused so far but may be useful in future */
static bool option_is_birth(int opt) { return opt >= OPT_BIRTH && opt < (OPT_BIRTH + N_OPTS_BIRTH); }
static bool option_is_score(int opt) { return opt >= OPT_SCORE && opt < (OPT_SCORE + N_OPTS_CHEAT); }
#endif

static bool option_is_cheat(int opt) { return opt >= OPT_CHEAT && opt < (OPT_CHEAT + N_OPTS_CHEAT); }

/* Setup functions */
bool option_set(const char *name, int val)
{
	size_t opt;

	/* Try normal options first */
	for (opt = 0; opt < OPT_MAX; opt++) {
		if (!options[opt].name || !streq(options[opt].name, name))
			continue;

		op_ptr->opt[opt] = val ? TRUE : FALSE;
		if (val && option_is_cheat(opt))
			op_ptr->opt[opt + (OPT_SCORE - OPT_CHEAT)] = TRUE;

		return TRUE;
	}

	if (streq(name, "hp_warn_factor")) {
		op_ptr->hitpoint_warn = val;
	} else if (streq(name, "delay_factor")) {
		op_ptr->delay_factor = val;
	} else {
		return FALSE;
	}

	return TRUE;
}

void option_set_defaults(void)
{
	size_t opt;
	for (opt = 0; opt < OPT_MAX; opt++)
		op_ptr->opt[opt] = options[opt].normal;

	/* 40ms for the delay factor */
	op_ptr->delay_factor = 40;

	/* 30% of HP */
	op_ptr->hitpoint_warn = 3;
}


/*
 * Write all current options to a user preference file.
 */
void option_dump(ang_file *f)
{
	int i, j;

	file_putf(f, "# Options\n");

	/* Dump options (skip cheat, score) */
	for (i = 0; i < OPT_CHEAT; i++) {
		const char *name = option_name(i);
		if (name)
			file_putf(f, "%c:%s\n", op_ptr->opt[i] ? 'Y' : 'X', name);
	}

	file_putf(f, "O:hp_warn_factor:%d\n", op_ptr->hitpoint_warn);
	file_putf(f, "O:delay_factor:%d\n", op_ptr->delay_factor);
	file_putf(f, "\n");

	/* Dump window flags */
	for (i = 1; i < ANGBAND_TERM_MAX; i++)
	{
		/* Require a real window */
		if (!angband_term[i]) continue;

		/* Check each flag */
		for (j = 0; j < (int)N_ELEMENTS(window_flag_desc); j++)
		{
			/* Require a real flag */
			if (!window_flag_desc[j]) continue;

			/* Comment */
			file_putf(f, "# Window '%s', Flag '%s'\n",
				angband_term_name[i], window_flag_desc[j]);

			/* Dump the flag */
			if (op_ptr->window_flag[i] & (1L << j))
				file_putf(f, "W:%d:%d:1\n", i, j);
			else
				file_putf(f, "W:%d:%d:0\n", i, j);

			/* Skip a line */
			file_putf(f, "\n");
		}
	}
}
