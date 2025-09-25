SpQueryContextAttributesFn Spquerycontextattributesfn;

NTSTATUS Spquerycontextattributesfn(
  [in]  LSA_SEC_HANDLE ContextHandle,
  [in]  ULONG ContextAttribute,
  [out] PVOID Buffer
)
{...}