PDXVAHDSW_GetVideoProcessorOutputFormats PdxvahdswGetvideoprocessoroutputformats;

HRESULT PdxvahdswGetvideoprocessoroutputformats(
  [in]  HANDLE hDevice,
  [in]  const DXVAHD_CONTENT_DESC *pContentDesc,
  [in]  DXVAHD_DEVICE_USAGE Usage,
  [in]  UINT Count,
  [out] D3DFORMAT *pFormats
)
{...}