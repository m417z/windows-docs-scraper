DWORD ResUtilPropertyListFromParameterBlock(
  [in]            const PRESUTIL_PROPERTY_ITEM pPropertyTable,
  [out, optional] PVOID                        pOutPropertyList,
  [in, out]       LPDWORD                      pcbOutPropertyListSize,
  [in]            const LPBYTE                 pInParams,
  [out]           LPDWORD                      pcbBytesReturned,
  [out]           LPDWORD                      pcbRequired
);