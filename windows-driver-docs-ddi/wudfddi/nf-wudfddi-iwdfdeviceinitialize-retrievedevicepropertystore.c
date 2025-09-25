HRESULT RetrieveDevicePropertyStore(
  [in, optional]  PCWSTR                            pcwszServiceName,
  [in]            WDF_PROPERTY_STORE_RETRIEVE_FLAGS Flags,
  [out]           IWDFNamedPropertyStore            **ppPropStore,
  [out, optional] WDF_PROPERTY_STORE_DISPOSITION    *pDisposition
);