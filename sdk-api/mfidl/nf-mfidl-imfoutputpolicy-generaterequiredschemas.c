HRESULT GenerateRequiredSchemas(
  [in]  DWORD         dwAttributes,
  [in]  GUID          guidOutputSubType,
  [in]  GUID          *rgGuidProtectionSchemasSupported,
  [in]  DWORD         cProtectionSchemasSupported,
  [out] IMFCollection **ppRequiredProtectionSchemas
);