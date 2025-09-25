DXGKDDI_OPM_DESTROY_PROTECTED_OUTPUT DxgkddiOpmDestroyProtectedOutput;

NTSTATUS DxgkddiOpmDestroyProtectedOutput(
  [in] PVOID MiniportDeviceContext,
  [in] HANDLE ProtectedOutputHandle
)
{...}