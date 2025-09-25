HRESULT EnclaveUnsealData(
  [in]            const VOID       *ProtectedBlob,
  [in]            UINT32           ProtectedBlobSize,
  [out]           PVOID            DecryptedData,
  [in]            UINT32           BufferSize,
  [out]           UINT32           *DecryptedDataSize,
  [out, optional] ENCLAVE_IDENTITY *SealingIdentity,
  [out, optional] UINT32           *UnsealingFlags
);