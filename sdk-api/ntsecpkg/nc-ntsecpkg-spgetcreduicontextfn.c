SpGetCredUIContextFn Spgetcreduicontextfn;

NTSTATUS Spgetcreduicontextfn(
  [in]  LSA_SEC_HANDLE ContextHandle,
  [in]  GUID *CredType,
  [out] PULONG FlatCredUIContextLength,
  [out] PUCHAR *FlatCredUIContext
)
{...}