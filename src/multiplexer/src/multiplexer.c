#include <stdbool.h>
#include "multiplexer.h"


void setAddress(struct tmux_inst* instance, int addr){
    instance->sel = addr % 8;
}

unsigned int getAddress(struct tmux_inst* instance){
    return instance->sel;
}

void enable(struct tmux_inst* inst){
    inst->enabled = true;
}

void disabled(struct tmux_inst* inst){
    inst->enabled = false;
}

bool isEnabled(struct tmux_inst* inst){
    return inst->enabled;
}

/*
 * What I would do here: I would make an "object"/Instance of each TMUX, which has an internal state, and set and get
 * methods for address, and for enabled, and it always will mod 8 the internal address
 */