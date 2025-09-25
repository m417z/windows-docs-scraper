DWORD ResUtilGetProperty(
  [in]      HKEY                         hkeyClusterKey,
  [in]      const PRESUTIL_PROPERTY_ITEM pPropertyTableItem,
  [out]     PVOID                        *pOutPropertyItem,
  [in, out] LPDWORD                      pcbOutPropertyItemSize
);