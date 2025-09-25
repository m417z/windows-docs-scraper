DWORD ResUtilVerifyPropertyTable(
  [in]            const PRESUTIL_PROPERTY_ITEM pPropertyTable,
                  PVOID                        Reserved,
  [in]            BOOL                         bAllowUnknownProperties,
  [in]            const PVOID                  pInPropertyList,
  [in]            DWORD                        cbInPropertyListSize,
  [out, optional] LPBYTE                       pOutParams
);