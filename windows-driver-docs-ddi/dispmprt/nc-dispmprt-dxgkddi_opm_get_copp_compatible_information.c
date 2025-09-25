DXGKDDI_OPM_GET_COPP_COMPATIBLE_INFORMATION DxgkddiOpmGetCoppCompatibleInformation;

NTSTATUS DxgkddiOpmGetCoppCompatibleInformation(
  [in]  PVOID MiniportDeviceContext,
  [in]  HANDLE ProtectedOutputHandle,
  [in]  const DXGKMDT_OPM_COPP_COMPATIBLE_GET_INFO_PARAMETERS *Parameters,
  [out] PDXGKMDT_OPM_REQUESTED_INFORMATION RequestedInformation
)
{...}