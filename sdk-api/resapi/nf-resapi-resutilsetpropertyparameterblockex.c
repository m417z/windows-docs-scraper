DWORD ResUtilSetPropertyParameterBlockEx(
  [in]            HKEY                         hkeyClusterKey,
  [in]            const PRESUTIL_PROPERTY_ITEM pPropertyTable,
  [in]            PVOID                        Reserved,
  [in]            const LPBYTE                 pInParams,
  [in]            const PVOID                  pInPropertyList,
  [in]            DWORD                        cbInPropertyListSize,
  [in]            BOOL                         bForceWrite,
  [out, optional] LPBYTE                       pOutParams
);