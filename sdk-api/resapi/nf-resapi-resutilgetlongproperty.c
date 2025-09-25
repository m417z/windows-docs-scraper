DWORD ResUtilGetLongProperty(
  [out] [out] LPLONG               plOutValue,
  [in] [in]   const PCLUSPROP_LONG pValueStruct,
  [in] [in]   LONG                 lOldValue,
  [in] [in]   LONG                 lMinimum,
  [in] [in]   LONG                 lMaximum,
  [out] [out] LPBYTE               *ppPropertyList,
  [out] [out] LPDWORD              pcbPropertyListSize
);