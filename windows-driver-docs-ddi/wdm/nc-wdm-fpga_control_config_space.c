FPGA_CONTROL_CONFIG_SPACE FpgaControlConfigSpace;

NTSTATUS FpgaControlConfigSpace(
  [_In_reads_opt_(_Inexpressible_("varies"))] PVOID Context,
  [_In_]                                      BOOLEAN Enable
)
{...}