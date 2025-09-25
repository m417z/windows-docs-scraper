DXGKDDI_VIDPNTOPOLOGY_GETNUMPATHSFROMSOURCE DxgkddiVidpntopologyGetnumpathsfromsource;

NTSTATUS DxgkddiVidpntopologyGetnumpathsfromsource(
  [in]  IN_CONST_D3DKMDT_HVIDPNTOPOLOGY hVidPnTopology,
  [in]  IN_CONST_D3DDDI_VIDEO_PRESENT_SOURCE_ID VidPnSourceId,
  [out] OUT_PSIZE_T pNumPathsFromSource
)
{...}