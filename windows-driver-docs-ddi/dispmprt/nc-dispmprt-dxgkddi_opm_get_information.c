DXGKDDI_OPM_GET_INFORMATION DxgkddiOpmGetInformation;

NTSTATUS DxgkddiOpmGetInformation(
  [in]  PVOID MiniportDeviceContext,
  [in]  HANDLE ProtectedOutputHandle,
  [in]  const DXGKMDT_OPM_GET_INFO_PARAMETERS *Parameters,
  [out] PDXGKMDT_OPM_REQUESTED_INFORMATION RequestedInformation
)
{...}