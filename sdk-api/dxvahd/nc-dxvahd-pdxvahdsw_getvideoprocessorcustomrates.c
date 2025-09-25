PDXVAHDSW_GetVideoProcessorCustomRates PdxvahdswGetvideoprocessorcustomrates;

HRESULT PdxvahdswGetvideoprocessorcustomrates(
  [in]  HANDLE hDevice,
  [in]  const GUID *pVPGuid,
  [in]  UINT Count,
  [out] DXVAHD_CUSTOM_RATE_DATA *pRates
)
{...}