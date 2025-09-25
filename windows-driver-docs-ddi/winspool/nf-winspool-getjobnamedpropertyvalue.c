DWORD GetJobNamedPropertyValue(
  [in]  HANDLE             hPrinter,
  [in]  DWORD              JobId,
  [in]  PCWSTR             pszName,
  [out] PrintPropertyValue *pValue
);