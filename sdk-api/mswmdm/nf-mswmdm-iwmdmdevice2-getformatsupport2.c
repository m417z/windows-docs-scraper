HRESULT GetFormatSupport2(
  [in]  DWORD              dwFlags,
  [out] _WAVEFORMATEX      **ppAudioFormatEx,
  [out] UINT               *pnAudioFormatCount,
  [out] _VIDEOINFOHEADER   **ppVideoFormatEx,
  [out] UINT               *pnVideoFormatCount,
  [out] WMFILECAPABILITIES **ppFileType,
  [out] UINT               *pnFileTypeCount
);