HRESULT Acquire(
  [in] IPhotoAcquireSource     *pPhotoAcquireSource,
  [in] BOOL                    fShowProgress,
  [in] HWND                    hWndParent,
  [in] LPCWSTR                 pszApplicationName,
  [in] IPhotoAcquireProgressCB *pPhotoAcquireProgressCB
);