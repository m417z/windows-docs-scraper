PDXVAHDSW_GetVideoProcessorDeviceCaps PdxvahdswGetvideoprocessordevicecaps;

HRESULT PdxvahdswGetvideoprocessordevicecaps(
  [in]  HANDLE hDevice,
  [in]  const DXVAHD_CONTENT_DESC *pContentDesc,
  [in]  DXVAHD_DEVICE_USAGE Usage,
  [out] DXVAHD_VPDEVCAPS *pCaps
)
{...}