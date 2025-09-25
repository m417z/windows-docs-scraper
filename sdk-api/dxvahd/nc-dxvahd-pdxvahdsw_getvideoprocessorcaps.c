PDXVAHDSW_GetVideoProcessorCaps PdxvahdswGetvideoprocessorcaps;

HRESULT PdxvahdswGetvideoprocessorcaps(
  [in]  HANDLE hDevice,
  [in]  const DXVAHD_CONTENT_DESC *pContentDesc,
  [in]  DXVAHD_DEVICE_USAGE Usage,
  [in]  UINT Count,
  [out] DXVAHD_VPCAPS *pCaps
)
{...}