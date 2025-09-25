HRESULT RetrieveDevicePropertyStore(
  [in]  PWDF_PROPERTY_STORE_ROOT          RootSpecifier,
  [in]  WDF_PROPERTY_STORE_RETRIEVE_FLAGS Flags,
  [in]  REGSAM                            DesiredAccess,
  [in]  PCWSTR                            SubkeyPath,
  [out] IWDFNamedPropertyStore2           **PropertyStore,
  [out] WDF_PROPERTY_STORE_DISPOSITION    *Disposition
);