DXGKDDI_START_DEVICE DxgkddiStartDevice;

NTSTATUS DxgkddiStartDevice(
  [in]  IN_CONST_PVOID MiniportDeviceContext,
  [in]  IN_PDXGK_START_INFO DxgkStartInfo,
  [in]  IN_PDXGKRNL_INTERFACE DxgkInterface,
  [out] OUT_PULONG NumberOfVideoPresentSources,
  [out] OUT_PULONG NumberOfChildren
)
{...}