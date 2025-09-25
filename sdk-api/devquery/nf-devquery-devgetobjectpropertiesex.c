HRESULT DevGetObjectPropertiesEx(
  [in]  DEV_OBJECT_TYPE           ObjectType,
  [in]  PCWSTR                    pszObjectId,
  [in]  ULONG                     QueryFlags,
  [in]  ULONG                     cRequestedProperties,
  [in]  const DEVPROPCOMPKEY      *pRequestedProperties,
  [in]  ULONG                     cExtendedParameterCount,
  [in]  const DEV_QUERY_PARAMETER *pExtendedParameters,
  [out] PULONG                    pcPropertyCount,
  [out] const DEVPROPERTY         **ppProperties
);