HRESULT DevGetObjects(
  [in]           DEV_OBJECT_TYPE                 ObjectType,
  [in]           ULONG                           QueryFlags,
  [in]           ULONG                           cRequestedProperties,
  [in, optional] const DEVPROPCOMPKEY            *pRequestedProperties,
  [in]           ULONG                           cFilterExpressionCount,
  [in, optional] const DEVPROP_FILTER_EXPRESSION *pFilter,
  [out]          PULONG                          pcObjectCount,
  [out]          const DEV_OBJECT                **ppObjects
);