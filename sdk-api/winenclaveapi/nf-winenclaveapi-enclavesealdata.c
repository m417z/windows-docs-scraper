HRESULT EnclaveSealData(
  [in]  const VOID                      *DataToEncrypt,
  [in]  UINT32                          DataToEncryptSize,
  [in]  ENCLAVE_SEALING_IDENTITY_POLICY IdentityPolicy,
  [in]  UINT32                          RuntimePolicy,
  [out] PVOID                           ProtectedBlob,
  [in]  UINT32                          BufferSize,
  [out] UINT32                          *ProtectedBlobSize
);