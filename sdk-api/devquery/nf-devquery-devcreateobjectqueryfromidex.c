HRESULT DevCreateObjectQueryFromIdEx(
  [in]           DEV_OBJECT_TYPE                 ObjectType,
  [in]           PCWSTR                          pszObjectId,
  [in]           ULONG                           QueryFlags,
  [in]           ULONG                           cRequestedProperties,
  [in, optional] const DEVPROPCOMPKEY            *pRequestedProperties,
  [in]           ULONG                           cFilterExpressionCount,
  [in, optional] const DEVPROP_FILTER_EXPRESSION *pFilter,
  [in]           ULONG                           cExtendedParameterCount,
  [in, optional] const DEV_QUERY_PARAMETER       *pExtendedParameters,
  [in]           PDEV_QUERY_RESULT_CALLBACK      pCallback,
  [in, optional] PVOID                           pContext,
  [out]          PHDEVQUERY                      phDevQuery
);