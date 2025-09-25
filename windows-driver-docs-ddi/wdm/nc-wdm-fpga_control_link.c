FPGA_CONTROL_LINK FpgaControlLink;

NTSTATUS FpgaControlLink(
  [_In_reads_opt_(_Inexpressible_("varies"))] PVOID Context,
  [_In_]                                      BOOLEAN Enable
)
{...}