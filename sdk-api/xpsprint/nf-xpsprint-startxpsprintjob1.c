HRESULT StartXpsPrintJob1(
  [in]            LPCWSTR             printerName,
  [in, optional]  LPCWSTR             jobName,
  [in, optional]  LPCWSTR             outputFileName,
  [in, optional]  HANDLE              progressEvent,
  [in, optional]  HANDLE              completionEvent,
  [out, optional] IXpsPrintJob        **xpsPrintJob,
  [out]           IXpsOMPackageTarget **printContentReceiver
);