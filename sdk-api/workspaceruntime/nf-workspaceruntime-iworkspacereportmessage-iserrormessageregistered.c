HRESULT IsErrorMessageRegistered(
  [in]          BSTR         bstrWkspId,
  [in]          DWORD        dwErrorType,
  [in]          BSTR         bstrErrorMessageType,
  [in]          DWORD        dwErrorCode,
  [out, retval] VARIANT_BOOL *pfErrorExist
);