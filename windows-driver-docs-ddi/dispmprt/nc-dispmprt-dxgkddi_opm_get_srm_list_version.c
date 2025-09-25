DXGKDDI_OPM_GET_SRM_LIST_VERSION DxgkddiOpmGetSrmListVersion;

NTSTATUS DxgkddiOpmGetSrmListVersion(
  PVOID MiniportDeviceContext,
  PULONG SrmListVersionSize,
  PVOID SrmListVersionBuffer
)
{...}