BOOL CryptHashMessage(
  [in]                PCRYPT_HASH_MESSAGE_PARA pHashPara,
  [in]                BOOL                     fDetachedHash,
  [in]                DWORD                    cToBeHashed,
  [in]                const BYTE * []          rgpbToBeHashed,
  [in]                DWORD []                 rgcbToBeHashed,
  [out]               BYTE                     *pbHashedBlob,
  [in, out]           DWORD                    *pcbHashedBlob,
  [out, optional]     BYTE                     *pbComputedHash,
  [in, out, optional] DWORD                    *pcbComputedHash
);