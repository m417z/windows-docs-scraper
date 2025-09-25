HRESULT BeginDownload(
  [in]  IUnknown     *onProgressChanged,
  [in]  IUnknown     *onCompleted,
  [in]  VARIANT      state,
  [out] IDownloadJob **retval
);