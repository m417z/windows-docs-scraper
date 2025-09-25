D3COLD_REQUEST_PERST_DELAY D3coldRequestPerstDelay;

NTSTATUS D3coldRequestPerstDelay(
  [_In_reads_opt_(_Inexpressible_("varies"))] PVOID Context,
  [_In_]                                      ULONG DelayInMicroSeconds
)
{...}