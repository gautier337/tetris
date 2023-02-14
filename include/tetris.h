/*
** EPITECH PROJECT, 2022
** Header for Tetris
** File description:
** Xavier VINCENT - Gautier BONHUR
*/

#ifndef TETRIS_H_
    #define TETRIS_H_

// Libs
    #include <ncurses.h>
    #include <signal.h>
    #include <unistd.h>
    #include <time.h>
    #include "../lib/my/my.h"
    #include "../lib/my_printf/my_printf.h"

// Macros
    #define SUCCESS 0
    #define ERROR 84
    #define END 0
    #define PLAY 1
    #define PAUSE 2

    #define MAP_LINE_POS 0
    #define MAP_COL_POS 0

    #define DATA_BEST_SCORE_FILE "best_score.dat"

// Structures
    typedef struct keys {
        int left;
        int right;
        int turn;
        int drop;
        int quit;
        int pause;
    } keys_t;

    typedef struct options {
        int level;
        keys_t *keys;
        int next;
        int debug;
    } options_t;

    typedef struct map {
        char **map;
        int nb_lines;
        int nb_cols;
    } map_t;

    typedef struct tetrimino {
        char **pattern;
        int width;
        int height;
        int color;
    } tetrimino_t;

    typedef struct data {
        int max_width_tetrimino;
        int max_height_tetrimino;
        int max_size_tetrimino;
        int score;
        int best_score;
        int current_level;
        float timer;
        time_t start;
        time_t end;
    } data_t;

    typedef struct tetrimino_status {
        int tetrimino_next;
        int tetrimino_moving;
    } tetrimino_status_t;

    typedef struct game {
        int running_status;
        options_t *options;
        map_t *map;
        tetrimino_t **tetriminos;
        tetrimino_status_t *tetrimino_status;
        data_t *data;
        WINDOW *map_window;
        WINDOW *name_window;
        WINDOW *next_window;
        WINDOW *score_window;
        int nb_valid_tetriminos;
    } game_t;

// Debug
    int print_debug(game_t *game);
    int print_cat_tetriminos(const char *filepath, char *name);
    int display_tetrimino(char *filepath, int nbr_error);

// Errors
    // check_tetrimino.c
    int check_tetrimino(char const *filepath);
    int check_same_keys(game_t *game);
    int get_nbr_tetriminos(void);

    // help.c
    int print_help(const char *filename);

// Event
    // check_event.c
    void check_event(game_t *game, int ch);
    int check_sides_move(game_t *game, int right_or_left);
    void down_tetriminos(game_t *game);

// Free
    // free_all.c
    int free_all(game_t *game);

// Init
    // data.c
    int init_data(game_t *game);

    // key_bindings.c
    int get_key_bindings(game_t *game, const char **args);

    // load_map.c
    char **make_map(int lenght_first_line, int nbr_rows, game_t *game);
    char *set_string(int i, int lenght_first_line, char *string);

    // map_size.c
    int init_map_size(game_t *game, const char *string);

    // options.c
    int get_options(game_t *game, const char **args);

    // struct.c
    game_t *init_struct(const char **args);

    // tetriminos.c
    int valid_tetriminos(void);
    int init_tetriminos(game_t *game);

// Tools
    // create_tetriminos.c
    int create_tetrimino(game_t *game);
    void reset_moving_status(char **map);

    // data.c
    void save_value_in_file(int value, const char filepath[]);
    int get_value_from_file(const char path[]);

    // draw_tetriminos.c
    void draw_tetriminos(game_t *game, int y, int x);

    // draw_windows.c
    void draw_window_borders(WINDOW *window);
    int draw_window_map(game_t *game);
    int draw_window_name(game_t *game);
    int draw_window_next(game_t *game);
    int draw_window_score(game_t *game);

    // get_time.c
    char *get_time(game_t *game);

    // my_tetris_getnbr.c
    int my_getnbr_t(char const *str);

    // windows.c
    int init_windows_size(game_t *game);
    int init_ncurses(game_t *game);
    void clear_windows(game_t *game);
    void refresh_windows(game_t *game);

// display_game.c
int display_all(game_t *game);

// tetris.c
int tetris(const char **args);

#endif /* !TETRIS_H_ */
