PDXVAHDSW_SetVideoProcessStreamState PdxvahdswSetvideoprocessstreamstate;

HRESULT PdxvahdswSetvideoprocessstreamstate(
  [in] HANDLE hVideoProcessor,
  [in] UINT StreamNumber,
  [in] DXVAHD_STREAM_STATE State,
  [in] UINT DataSize,
  [in] const void *pData
)
{...}