DXGKDDI_VIDPN_ASSIGNMULTISAMPLINGMETHODSET DxgkddiVidpnAssignmultisamplingmethodset;

NTSTATUS DxgkddiVidpnAssignmultisamplingmethodset(
  [in] IN_D3DKMDT_HVIDPN hVidPn,
  [in] IN_CONST_D3DDDI_VIDEO_PRESENT_SOURCE_ID VidPnSourceId,
  [in] IN_CONST_SIZE_T NumMethods,
  [in] const D3DDDI_MULTISAMPLINGMETHOD *pSupportedMethodSet
)
{...}