HRESULT Show(
  [in]          ULONG_PTR          parentWnd,
  [in]          BSTR               accessPath,
  [in]          AdrClientErrorType errorType,
  [in]          long               flags,
  [in]          BSTR               windowTitle,
  [in]          BSTR               windowMessage,
  [out, retval] long               *result
);