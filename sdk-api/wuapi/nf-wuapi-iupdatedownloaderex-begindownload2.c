HRESULT BeginDownload2(
  DownloadType downloadType,
  IUnknown     *onProgressChanged,
  IUnknown     *onCompleted,
  VARIANT      state,
  IDownloadJob **retval
);