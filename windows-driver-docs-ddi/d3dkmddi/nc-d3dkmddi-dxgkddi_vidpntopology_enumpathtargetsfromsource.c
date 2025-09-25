DXGKDDI_VIDPNTOPOLOGY_ENUMPATHTARGETSFROMSOURCE DxgkddiVidpntopologyEnumpathtargetsfromsource;

NTSTATUS DxgkddiVidpntopologyEnumpathtargetsfromsource(
  [in]  IN_CONST_D3DKMDT_HVIDPNTOPOLOGY hVidPnTopology,
  [in]  IN_CONST_D3DDDI_VIDEO_PRESENT_SOURCE_ID VidPnSourceId,
  [in]  IN_CONST_D3DKMDT_VIDPN_PRESENT_PATH_INDEX VidPnPresentPathIndex,
  [out] OUT_PD3DDDI_VIDEO_PRESENT_TARGET_ID pVidPnTargetId
)
{...}