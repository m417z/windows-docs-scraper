PDXVAHDSW_GetVideoProcessStreamStatePrivate PdxvahdswGetvideoprocessstreamstateprivate;

HRESULT PdxvahdswGetvideoprocessstreamstateprivate(
  [in]      HANDLE hVideoProcessor,
  [in]      UINT StreamNumber,
  [in, out] DXVAHD_STREAM_STATE_PRIVATE_DATA *pData
)
{...}