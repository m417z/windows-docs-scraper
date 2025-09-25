HRESULT CreateContentDecryptionModuleAccess(
  LPCWSTR                          keySystem,
  IPropertyStore                   **configurations,
  DWORD                            numConfigurations,
  IMFContentDecryptionModuleAccess **contentDecryptionModuleAccess
);