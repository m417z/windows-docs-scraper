PMRX_CHKDIR_CALLDOWN PmrxChkdirCalldown;

NTSTATUS PmrxChkdirCalldown(
  [in, out] IN OUT PRX_CONTEXT RxContext,
  [in]      IN PUNICODE_STRING DirectoryName
)
{...}