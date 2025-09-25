DXGKDDI_SYSTEM_DISPLAY_ENABLE DxgkddiSystemDisplayEnable;

NTSTATUS DxgkddiSystemDisplayEnable(
  [in]  PVOID MiniportDeviceContext,
  [in]  D3DDDI_VIDEO_PRESENT_TARGET_ID TargetId,
  [in]  PDXGKARG_SYSTEM_DISPLAY_ENABLE_FLAGS Flags,
  [out] UINT *Width,
  [out] UINT *Height,
  [out] D3DDDIFORMAT *ColorFormat
)
{...}