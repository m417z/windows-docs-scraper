DXGKDDI_SETTARGETADJUSTEDCOLORIMETRY DxgkddiSettargetadjustedcolorimetry;

NTSTATUS DxgkddiSettargetadjustedcolorimetry(
  [in] IN_CONST_HANDLE hAdapter,
  [in] IN D3DDDI_VIDEO_PRESENT_TARGET_ID TargetId,
  [in] IN DXGK_COLORIMETRY AdjustedColorimetry
)
{...}