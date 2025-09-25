DXGKDDI_VIDPNTOPOLOGY_GETPATHSOURCEFROMTARGET DxgkddiVidpntopologyGetpathsourcefromtarget;

NTSTATUS DxgkddiVidpntopologyGetpathsourcefromtarget(
  [in]  IN_CONST_D3DKMDT_HVIDPNTOPOLOGY hVidTopology,
  [in]  IN_CONST_D3DDDI_VIDEO_PRESENT_TARGET_ID VidPnTargetId,
  [out] OUT_PD3DDDI_VIDEO_PRESENT_SOURCE_ID pVidPnSourceId
)
{...}