#include "qemu/osdep.h"
#include "exec/cpu_ldst.h"
#include "sysemu/x-ray.h"
#include "x-ray-internal.h"

static void simple_kernfn_hook (CPUArchState* env, uint64_t addr) {
    #ifdef TARGET_AARCH64
    uint32_t cnt;
    target_ulong urb_ptr;
    target_ulong data_ptr;
    char buf [1024];
    int i;
    char c;
    bzero (buf, 1024);
    urb_ptr = env->xregs[0];
    cnt = cpu_ldl_data(env, urb_ptr + 0x84);
    data_ptr = cpu_ldq_data(env, urb_ptr + 0x60);
    for (i = 0; i < cnt; i++) {
        if (i >= 1024) break;
        c = cpu_ldub_data (env, data_ptr + i);
        cpu_stb_taint (env, data_ptr + i, 0xFF);
        buf[i] = c;
    }
    printf ("ftdi_process_read_urb: tainting %d bytes data to [0x%lX]\n", cnt, data_ptr);
    #endif
}

void hook_register (void) {
    x_ray_add_kernel_hook ("ftdi_process_read_urb", simple_kernfn_hook);
}