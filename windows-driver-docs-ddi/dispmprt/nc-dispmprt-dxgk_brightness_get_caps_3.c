DXGK_BRIGHTNESS_GET_CAPS_3 DxgkBrightnessGetCaps3;

NTSTATUS DxgkBrightnessGetCaps3(
  [in]  PVOID Context,
  [in]  ULONG ChildUid,
  [out] DXGK_BRIGHTNESS_CAPS *pBrightnessCaps
)
{...}