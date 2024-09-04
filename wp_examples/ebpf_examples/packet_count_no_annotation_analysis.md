[kernel] Parsing packet_count.c (with preprocessing)
In file included from my_linux/linux/bpf.h:11,
                 from /home/swarnp/research/Frama-c/wp_examples/ebpf_examples/packet_count.c:1:
my_linux/linux/types.h:10:2: warning: #warning "Attempt to use kernel headers from user space, see https://kernelnewbies.org/KernelHeaders" [-Wcpp]
   10 | #warning "Attempt to use kernel headers from user space, see https://kernelnewbies.org/KernelHeaders"
      |  ^~~~~~~
cc1: note: unrecognized command-line option ‘-Wno-unknown-warning-option’ may have been intended to silence earlier diagnostics
[rte:annot] annotating function packet_count
[wp] packet_count.c:7: Warning: 
  In 'packet_count', no 'calls' specification for statement(s) on line(s): 
  line 8, 
  Assuming that they can call 'packet_count'
[wp] packet_count.c:8: Warning: Missing 'calls' for default behavior
[wp] packet_count.c:8: Warning: Unknown callee, considering non-terminating call
[wp] packet_count.c:8: Warning: 
  Missing decreases clause on recursive function packet_count, call must be unreachable
[wp] packet_count.c:8: Warning: 
  \valid_function not yet implemented
  (rte: function_pointer: \valid_function(bpf_trace_printk))
[wp] my_linux/bpf_helper_defs.h:177: Warning: 
  Cast with incompatible pointers types (source: sint8*) (target: void**)
[wp] 4 goals scheduled
[wp] [Timeout] typed_packet_count_assert_rte_function_pointer (Qed 0.95ms) (Alt-Ergo) (Degenerated)
[wp] [Timeout] typed_packet_count_assert_rte_signed_overflow (Qed 1ms) (Alt-Ergo) (Stronger)
[wp] [Timeout] typed_packet_count_terminates_part2 (Qed 0.83ms) (Alt-Ergo) (Stronger)
[wp] [Timeout] typed_packet_count_terminates_part1 (Qed 1ms) (Alt-Ergo) (Stronger)
[wp] Proved goals:    1 / 5
  Unreachable:     1
  Qed:             0 (0.83ms-1ms)
  Timeout:         4
[wp:pedantic-assigns] packet_count.c:7: Warning: 
  No 'assigns' specification for function 'packet_count'.
  Callers assumptions might be imprecise.
[report] Computing properties status...

--------------------------------------------------------------------------------
--- Properties of Function 'packet_count'
--------------------------------------------------------------------------------

[  Valid  ] Exit-condition (generated)
            by Unreachable Annotations.
[    -    ] Termination-condition (generated)
            tried with Wp.typed.
[    -    ] Assertion 'rte,function_pointer' (file packet_count.c, line 8)
            tried with Wp.typed.
[    -    ] Assertion 'rte,signed_overflow' (file packet_count.c, line 9)
            tried with Wp.typed.
[  Valid  ] Default behavior
            by Frama-C kernel.

--------------------------------------------------------------------------------
--- Status Report Summary
--------------------------------------------------------------------------------
     2 Completely validated
     3 To be validated
     5 Total
--------------------------------------------------------------------------------
