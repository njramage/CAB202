#include "game.h"

#define String char*

/* Draw current level */
void setup_level( Game * game )
{
	game->lives = 3;
	game->score = 0;
	game->level = 1;
	
	int level1_HUD_height = screen_height() - 1;
	int level2_HUD_height = screen_height() - 2;
	int level3_HUD_height = screen_height() - 3;

	int score_lives_len = snprintf( NULL, 0, "Score: %d   Lives: %d   ", game->score, game->lives );
	int level_text_len = snprintf( NULL, 0, "Level: %d - Basic", game->lives ); 
	int left_score_lives = ( screen_width() / 2 ) + ( score_lives_len - 2 );
	int left_level = ( screen_width() / 2 ) - ( level_text_len / 2 );
	
	draw_formatted( left_level, level1_HUD_height, "Level: %d - Basic", game->level);
	draw_formatted( 0, level2_HUD_height, "Nathan Ramage (n8802530)");
	draw_formatted( left_score_lives, level2_HUD_height, "Score: %d   Lives: %d   ", game->score, game->lives );
	draw_line( 0, level3_HUD_height, screen_width(), level3_HUD_height, '_');
}

void draw_level( Game * game )
{
	int level1_HUD_height = screen_height() - 1;
	int level2_HUD_height = screen_height() - 2;
	int level3_HUD_height = screen_height() - 3;

	int score_lives_len = snprintf( NULL, 0, "Score: %d   Lives: %d   ", game->score, game->lives );
	int level_text_len = snprintf( NULL, 0, "Level: %d - Basic", game->lives ); 
	int left_score_lives = ( screen_width() / 2 ) + ( score_lives_len - 2 );
	int left_level = ( screen_width() / 2 ) - ( level_text_len / 2 );
	
	draw_formatted( left_level, level1_HUD_height, "Level: %d - Basic", game->level);
	draw_formatted( 0, level2_HUD_height, "Nathan Ramage (n8802530)");
	draw_formatted( left_score_lives, level2_HUD_height, "Score: %d   Lives: %d   ", game->score, game->lives );
	draw_line( 0, level3_HUD_height, screen_width(), level3_HUD_height, '_');
}

void draw_game( Alien * alien, Game * game )
{
	clear_screen();
	draw_bombs( alien );
	draw_aliens( alien );
	draw_player( player );
	draw_level( game );
	/*for ( int i = 0; i < NUM_ALIENS; i++ )
	{
		draw_formatted( 0, 6 + i, "Alien %d last_bomb = %d", i + 1, alien->last_bomb[i] );
	}*/
	show_screen();
}

int play_turn( Alien * alien )
{
	int result = TURN_READY;
	int key = get_char();

	if ( key == 'q' || key == 'Q' )
	{
		result = TURN_GAME_OVER;
	}
	else if ( key == 'r' || key == 'R' )
	{
		result = TURN_READY;
	}

	if ( update_player( key ) )
	{
		result = TURN_SCREEN_CHANGED;
	}
	else if ( update_aliens( alien ) )
	{
		result = TURN_SCREEN_CHANGED;
	}

	return result;
}
