PMRX_EXTENDFILE_CALLDOWN MRxExtendForNonCache;

ULONG MRxExtendForNonCache(
  _Inout_ PRX_CONTEXT    RxContext,
  _Inout_ PLARGE_INTEGER pNewFileSize,
  _Out_   PLARGE_INTEGER pNewAllocationSize
)
{ ... }