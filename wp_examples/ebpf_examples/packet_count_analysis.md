[kernel] Parsing packet_count.c (with preprocessing)
In file included from my_linux/linux/bpf.h:11,
                 from /home/swarnp/research/Frama-c/wp_examples/ebpf_examples/packet_count.c:1:
my_linux/linux/types.h:10:2: warning: #warning "Attempt to use kernel headers from user space, see https://kernelnewbies.org/KernelHeaders" [-Wcpp]
   10 | #warning "Attempt to use kernel headers from user space, see https://kernelnewbies.org/KernelHeaders"
      |  ^~~~~~~
cc1: note: unrecognized command-line option ‘-Wno-unknown-warning-option’ may have been intended to silence earlier diagnostics
[wp] packet_count.c:12: Warning: 
  In 'packet_count', no 'calls' specification for statement(s) on line(s): 
  line 13, 
  Assuming that they can call 'packet_count'
[wp] Warning: Missing RTE guards
[wp] packet_count.c:13: Warning: Missing 'calls' for default behavior
[wp] packet_count.c:13: Warning: 
  Unknown callee, considering non-terminating call
[wp] packet_count.c:13: Warning: 
  Missing decreases clause on recursive function packet_count, call must be unreachable
[wp] my_linux/bpf_helper_defs.h:177: Warning: 
  Cast with incompatible pointers types (source: sint8*) (target: void**)
[wp] 3 goals scheduled
[wp] [Timeout] typed_packet_count_terminates_part2 (Qed 1ms) (Alt-Ergo)
[wp] [Timeout] typed_packet_count_terminates_part1 (Qed 1ms) (Alt-Ergo)
[wp] Proved goals:    2 / 4
  Unreachable:     1
  Qed:             1 (1ms-0.80ms-1ms)
  Timeout:         2
[wp:pedantic-assigns] packet_count.c:12: Warning: 
  No 'assigns' specification for function 'packet_count'.
  Callers assumptions might be imprecise.
[wp] packet_count.c:12: Warning: 
  Memory model hypotheses for function 'packet_count':
  /*@ behavior wp_typed:
        requires \separated(ctx, &counter); */
  int packet_count(struct xdp_md *ctx) __attribute__((__used__,
                                                      __section__("xdp")));
[report] Computing properties status...

--------------------------------------------------------------------------------
--- Properties of Function 'packet_count'
--------------------------------------------------------------------------------

[  Valid  ] Post-condition (file packet_count.c, line 8)
            by Wp.typed.
[  Valid  ] Exit-condition (generated)
            by Unreachable Annotations.
[    -    ] Termination-condition (generated)
            tried with Wp.typed.
[  Valid  ] Default behavior
            by Frama-C kernel.

--------------------------------------------------------------------------------
--- Status Report Summary
--------------------------------------------------------------------------------
     3 Completely validated
     1 To be validated
     4 Total
--------------------------------------------------------------------------------
