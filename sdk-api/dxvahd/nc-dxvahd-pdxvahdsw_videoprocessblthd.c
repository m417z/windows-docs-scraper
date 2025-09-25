PDXVAHDSW_VideoProcessBltHD PdxvahdswVideoprocessblthd;

HRESULT PdxvahdswVideoprocessblthd(
  [in] HANDLE hVideoProcessor,
  [in] IDirect3DSurface9 *pOutputSurface,
  [in] UINT OutputFrame,
  [in] UINT StreamCount,
  [in] const DXVAHD_STREAM_DATA *pStreams
)
{...}