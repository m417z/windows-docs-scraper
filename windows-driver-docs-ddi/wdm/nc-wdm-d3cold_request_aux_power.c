D3COLD_REQUEST_AUX_POWER D3coldRequestAuxPower;

NTSTATUS D3coldRequestAuxPower(
  [_In_reads_opt_(_Inexpressible_("varies"))] PVOID Context,
  [_In_]                                      ULONG AuxPowerInMilliWatts,
  [_Out_]                                     PULONG RetryInSeconds
)
{...}