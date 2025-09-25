DWORD ResUtilSetPropertyTableEx(
  [in]            HKEY                         hkeyClusterKey,
  [in]            const PRESUTIL_PROPERTY_ITEM pPropertyTable,
                  PVOID                        Reserved,
  [in]            BOOL                         bAllowUnknownProperties,
  [in]            const PVOID                  pInPropertyList,
  [in]            DWORD                        cbInPropertyListSize,
  [in]            BOOL                         bForceWrite,
  [out, optional] LPBYTE                       pOutParams
);