#include "qemu/osdep.h"
#include "qemu/thread.h"
#include "exec/cpu_ldst.h"
#include "exec/tb-flush.h"
#include "sysemu/cpus.h"
#include "hw/core/cpu.h"
#include "sysemu/x-ray.h"
#include "x-ray-internal.h"
#include "json.h"
#include "exec/helper-proto.h"

void HELPER (aarch64_update_task) (CPUArchState *env) {
    #ifdef TARGET_AARCH64

    #endif
}

void HELPER (aarch64_update_current_task) (CPUArchState *env) {
    #ifdef TARGET_AARCH64
    uint64_t next_ts_addr;
    TVM_task_struct *ts;
    next_ts_addr = env->xregs[1];
    CPUState* cpu = env_cpu (env);
    ts = x_ray_update_current_task (cpu, next_ts_addr);
    // if (ts != NULL) {
    //     cpu->current = *ts;
    // }
    #endif
}

void HELPER (x_ray_insert_hook) (CPUArchState *env, uint64_t fn_addr) {
    x_ray_hook_cb (env, fn_addr);
}