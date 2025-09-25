DXGK_BRIGHTNESS_GET_BACKLIGHT_REDUCTION DxgkBrightnessGetBacklightReduction;

NTSTATUS DxgkBrightnessGetBacklightReduction(
  [in]  PVOID Context,
  [out] DXGK_BACKLIGHT_INFO *BacklightInfo
)
{...}