DWORD ResUtilAddUnknownProperties(
  [in]      HKEY                         hkeyClusterKey,
  [in]      const PRESUTIL_PROPERTY_ITEM pPropertyTable,
  [in, out] PVOID                        pOutPropertyList,
  [in]      DWORD                        pcbOutPropertyListSize,
  [in, out] LPDWORD                      pcbBytesReturned,
  [in, out] LPDWORD                      pcbRequired
);