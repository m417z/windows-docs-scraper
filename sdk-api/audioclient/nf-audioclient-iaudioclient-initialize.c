HRESULT Initialize(
  [in] AUDCLNT_SHAREMODE  ShareMode,
  [in] DWORD              StreamFlags,
  [in] REFERENCE_TIME     hnsBufferDuration,
  [in] REFERENCE_TIME     hnsPeriodicity,
  [in] const WAVEFORMATEX *pFormat,
  [in] LPCGUID            AudioSessionGuid
);