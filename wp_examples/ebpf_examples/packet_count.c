#include <linux/bpf.h>
#include <bpf/bpf_helpers.h>

int counter = 0;

SEC("xdp")
int packet_count(void *ctx) {
    bpf_printk("%d", counter);
    counter++;
    return XDP_PASS;
}

char LICENSE[] SEC("license") = "Dual BSD/GPL";

//  frama-c -cpp-extra-args="-I my_linux -I $(frama-c -print-path)/linux" -wp -rte packet_count.c
