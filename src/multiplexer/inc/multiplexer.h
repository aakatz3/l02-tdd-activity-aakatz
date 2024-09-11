#ifndef MULTIPLEXER_H
#define MULTIPLEXER_H

// Any libraries needed here
#include <stdbool.h>

// Structures
struct tmux_inst {
    bool enabled;
    unsigned int sel; // Should be [0,7], int, maybe look at better data types
};


// Add the functions needed for your multiplexer functions
//typedef struct tmux_inst tmux_inst;
struct tmux_inst;
void setAddress(struct tmux_inst* instance, int addr);
unsigned int getAddress(struct tmux_inst* instance);
void enable(struct tmux_inst* inst);
void disabled(struct tmux_inst* inst);
bool isEnabled(struct tmux_inst* inst);

#endif
