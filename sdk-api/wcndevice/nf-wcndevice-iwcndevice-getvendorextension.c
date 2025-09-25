HRESULT GetVendorExtension(
  [in]  const WCN_VENDOR_EXTENSION_SPEC *pVendorExtSpec,
  [in]  DWORD                           dwMaxBufferSize,
  [out] BYTE []                         pbBuffer,
  [out] DWORD                           *pdwBufferUsed
);