BOOL CryptVerifyMessageHash(
  [in]                PCRYPT_HASH_MESSAGE_PARA pHashPara,
  [in]                BYTE                     *pbHashedBlob,
  [in]                DWORD                    cbHashedBlob,
  [out]               BYTE                     *pbToBeHashed,
  [in, out]           DWORD                    *pcbToBeHashed,
  [out, optional]     BYTE                     *pbComputedHash,
  [in, out, optional] DWORD                    *pcbComputedHash
);