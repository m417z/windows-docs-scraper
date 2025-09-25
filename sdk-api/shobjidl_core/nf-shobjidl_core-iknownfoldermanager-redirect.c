HRESULT Redirect(
  [in]           REFKNOWNFOLDERID    rfid,
  [in, optional] HWND                hwnd,
  [in]           KF_REDIRECT_FLAGS   flags,
  [in, optional] LPCWSTR             pszTargetPath,
  [in]           UINT                cFolders,
  [in]           const KNOWNFOLDERID *pExclusion,
  [out]          LPWSTR              *ppszError
);