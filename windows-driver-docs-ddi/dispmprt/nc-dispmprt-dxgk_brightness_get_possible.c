DXGK_BRIGHTNESS_GET_POSSIBLE DxgkBrightnessGetPossible;

NTSTATUS DxgkBrightnessGetPossible(
  [in]  PVOID Context,
  [in]  ULONG BufferSize,
  [out] PUCHAR LevelCount,
  [out] PUCHAR BrightnessLevels
)
{...}