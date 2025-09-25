HRESULT CreateStorage2(
  [in]  DWORD            dwAttributes,
  [in]  DWORD            dwAttributesEx,
  [in]  _WAVEFORMATEX    *pAudioFormat,
  [in]  _VIDEOINFOHEADER *pVideoFormat,
  [in]  LPWSTR           pwszName,
  [in]  ULONGLONG        qwFileSize,
  [out] IMDSPStorage     **ppNewStorage
);