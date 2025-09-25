DXGKCB_EXCLUDE_ADAPTER_ACCESS DxgkcbExcludeAdapterAccess;

NTSTATUS DxgkcbExcludeAdapterAccess(
  [in] HANDLE DeviceHandle,
  [in] ULONG Attributes,
  [in] DXGKDDI_PROTECTED_CALLBACK DxgkProtectedCallback,
  [in] PVOID ProtectedCallbackContext
)
{...}