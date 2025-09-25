DWORD ResUtilGetBinaryProperty(
  [out]          LPBYTE                 *ppbOutValue,
  [out]          LPDWORD                pcbOutValueSize,
  [in]           const PCLUSPROP_BINARY pValueStruct,
  [in, optional] const LPBYTE           pbOldValue,
  [in]           DWORD                  cbOldValueSize,
  [in, out]      LPBYTE                 *ppPropertyList,
  [in, out]      LPDWORD                pcbPropertyListSize
);