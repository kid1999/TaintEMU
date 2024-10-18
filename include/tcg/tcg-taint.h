#ifndef TCG_TAINT_H
#define TCG_TAINT_H
void taint_write_notify (uint64_t addr, uint64_t taint, uint64_t val, CPUArchState *env);

void taint_read_notify (uint64_t addr, uint64_t taint, uint64_t val, CPUArchState *env);

void taint_exec_notify (uint64_t addr, uint64_t taint); 
#endif