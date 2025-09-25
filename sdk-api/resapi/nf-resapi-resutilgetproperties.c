DWORD ResUtilGetProperties(
  [in]  HKEY                         hkeyClusterKey,
  [in]  const PRESUTIL_PROPERTY_ITEM pPropertyTable,
  [out] PVOID                        pOutPropertyList,
  [in]  DWORD                        cbOutPropertyListSize,
  [out] LPDWORD                      pcbBytesReturned,
  [out] LPDWORD                      pcbRequired
);