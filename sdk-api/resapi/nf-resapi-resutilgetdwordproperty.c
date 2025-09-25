DWORD ResUtilGetDwordProperty(
  [out] LPDWORD               pdwOutValue,
  [in]  const PCLUSPROP_DWORD pValueStruct,
  [in]  DWORD                 dwOldValue,
  [in]  DWORD                 dwMinimum,
  [in]  DWORD                 dwMaximum,
  [out] LPBYTE                *ppPropertyList,
  [out] LPDWORD               pcbPropertyListSize
);