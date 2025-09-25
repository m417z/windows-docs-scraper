DWORD ResUtilGetPropertiesToParameterBlock(
  [in]            HKEY                         hkeyClusterKey,
  [in]            const PRESUTIL_PROPERTY_ITEM pPropertyTable,
  [out]           LPBYTE                       pOutParams,
  [in]            BOOL                         bCheckForRequiredProperties,
  [out, optional] LPWSTR                       *pszNameOfPropInError
);