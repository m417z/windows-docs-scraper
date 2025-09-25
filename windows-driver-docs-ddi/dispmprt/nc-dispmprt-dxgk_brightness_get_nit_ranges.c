DXGK_BRIGHTNESS_GET_NIT_RANGES DxgkBrightnessGetNitRanges;

NTSTATUS DxgkBrightnessGetNitRanges(
  [in]  PVOID Context,
  [in]  ULONG ChildUid,
  [out] PDXGK_BRIGHTNESS_GET_NIT_RANGES_OUT pOut
)
{...}