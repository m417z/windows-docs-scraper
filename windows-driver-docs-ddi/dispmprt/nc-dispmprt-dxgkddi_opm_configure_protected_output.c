DXGKDDI_OPM_CONFIGURE_PROTECTED_OUTPUT DxgkddiOpmConfigureProtectedOutput;

NTSTATUS DxgkddiOpmConfigureProtectedOutput(
  [in] PVOID MiniportDeviceContext,
  [in] HANDLE ProtectedOutputHandle,
  [in] const DXGKMDT_OPM_CONFIGURE_PARAMETERS *Parameters,
  [in] ULONG AdditionalParametersSize,
  [in] const VOID *AdditionalParameters
)
{...}