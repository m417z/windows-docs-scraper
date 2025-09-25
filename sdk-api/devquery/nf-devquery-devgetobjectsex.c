HRESULT DevGetObjectsEx(
  [in]           DEV_OBJECT_TYPE                 ObjectType,
  [in]           ULONG                           QueryFlags,
  [in]           ULONG                           cRequestedProperties,
  [in, optional] const DEVPROPCOMPKEY            *pRequestedProperties,
  [in]           ULONG                           cFilterExpressionCount,
  [in, optional] const DEVPROP_FILTER_EXPRESSION *pFilter,
  [in]           ULONG                           cExtendedParameterCount,
  [in, optional] const DEV_QUERY_PARAMETER       *pExtendedParameters,
  [out]          PULONG                          pcObjectCount,
  [out]          const DEV_OBJECT                **ppObjects
);