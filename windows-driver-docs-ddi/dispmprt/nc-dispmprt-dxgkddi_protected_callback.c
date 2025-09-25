DXGKDDI_PROTECTED_CALLBACK DxgkddiProtectedCallback;

VOID DxgkddiProtectedCallback(
  [in] IN_CONST_PVOID MiniportDeviceContext,
  [in] PVOID ProtectedCallbackContext,
  [in] NTSTATUS ProtectionStatus
)
{...}