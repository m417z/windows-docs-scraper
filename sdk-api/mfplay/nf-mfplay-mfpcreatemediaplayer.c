HRESULT MFPCreateMediaPlayer(
  [in]  LPCWSTR                 pwszURL,
  [in]  BOOL                    fStartPlayback,
  [in]  MFP_CREATION_OPTIONS    creationOptions,
  [in]  IMFPMediaPlayerCallback *pCallback,
  [in]  HWND                    hWnd,
  [out] IMFPMediaPlayer         **ppMediaPlayer
);