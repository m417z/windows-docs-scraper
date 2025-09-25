HRESULT DevGetObjectProperties(
  [in]  DEV_OBJECT_TYPE      ObjectType,
  [in]  PCWSTR               pszObjectId,
  [in]  ULONG                QueryFlags,
  [in]  ULONG                cRequestedProperties,
  [in]  const DEVPROPCOMPKEY *pRequestedProperties,
  [out] PULONG               pcPropertyCount,
  [out] const DEVPROPERTY    **ppProperties
);