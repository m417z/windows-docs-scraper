DXGKCB_ACQUIRE_POST_DISPLAY_OWNERSHIP DxgkcbAcquirePostDisplayOwnership;

NTSTATUS DxgkcbAcquirePostDisplayOwnership(
  [in]  HANDLE DeviceHandle,
  [out] PDXGK_DISPLAY_INFORMATION DisplayInfo
)
{...}