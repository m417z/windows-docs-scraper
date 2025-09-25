DWORD ResUtilGetFileTimeProperty(
  [out] LPFILETIME               pftOutValue,
  [in]  const PCLUSPROP_FILETIME pValueStruct,
  [in]  FILETIME                 ftOldValue,
  [in]  FILETIME                 ftMinimum,
  [in]  FILETIME                 ftMaximum,
  [out] LPBYTE                   *ppPropertyList,
  [out] LPDWORD                  pcbPropertyListSize
);