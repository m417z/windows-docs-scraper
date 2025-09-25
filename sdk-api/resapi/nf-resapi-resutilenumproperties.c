DWORD ResUtilEnumProperties(
  [in]  const PRESUTIL_PROPERTY_ITEM pPropertyTable,
  [out] LPWSTR                       pszOutProperties,
  [in]  DWORD                        cbOutPropertiesSize,
  [out] LPDWORD                      pcbBytesReturned,
  [out] LPDWORD                      pcbRequired
);