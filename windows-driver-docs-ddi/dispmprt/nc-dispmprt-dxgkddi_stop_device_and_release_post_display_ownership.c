DXGKDDI_STOP_DEVICE_AND_RELEASE_POST_DISPLAY_OWNERSHIP DxgkddiStopDeviceAndReleasePostDisplayOwnership;

NTSTATUS DxgkddiStopDeviceAndReleasePostDisplayOwnership(
  [in]  PVOID MiniportDeviceContext,
  [in]  D3DDDI_VIDEO_PRESENT_TARGET_ID TargetId,
  [out] PDXGK_DISPLAY_INFORMATION DisplayInfo
)
{...}