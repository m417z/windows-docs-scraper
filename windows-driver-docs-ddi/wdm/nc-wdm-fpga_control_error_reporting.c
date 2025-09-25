FPGA_CONTROL_ERROR_REPORTING FpgaControlErrorReporting;

NTSTATUS FpgaControlErrorReporting(
  [_In_reads_opt_(_Inexpressible_("varies"))] PVOID Context,
  [_In_]                                      ULONG UncorrectableMask,
  [_In_]                                      ULONG CorrectableMask,
  [_In_]                                      BOOLEAN DisableErrorReporting
)
{...}