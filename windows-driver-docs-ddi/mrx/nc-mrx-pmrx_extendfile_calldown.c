PMRX_EXTENDFILE_CALLDOWN PmrxExtendfileCalldown;

ULONG PmrxExtendfileCalldown(
  IN OUT PRX_CONTEXT RxContext,
  IN OUT PLARGE_INTEGER NewFileSize,
  OUT PLARGE_INTEGER NewAllocationSize
)
{...}