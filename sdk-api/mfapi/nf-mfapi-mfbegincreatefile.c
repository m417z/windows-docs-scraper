HRESULT MFBeginCreateFile(
  [in]  MF_FILE_ACCESSMODE AccessMode,
  [in]  MF_FILE_OPENMODE   OpenMode,
  [in]  MF_FILE_FLAGS      fFlags,
  [in]  LPCWSTR            pwszFilePath,
  [in]  IMFAsyncCallback   *pCallback,
  [in]  IUnknown           *pState,
  [out] IUnknown           **ppCancelCookie
);