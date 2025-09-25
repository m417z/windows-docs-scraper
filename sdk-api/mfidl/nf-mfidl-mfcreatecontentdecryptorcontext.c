HRESULT MFCreateContentDecryptorContext(
  [in]           REFGUID                    guidMediaProtectionSystemId,
  [in, optional] IMFDXGIDeviceManager       *pD3DManager,
  [in]           IMFContentProtectionDevice *pContentProtectionDevice,
  [out]          IMFContentDecryptorContext **ppContentDecryptorContext
);