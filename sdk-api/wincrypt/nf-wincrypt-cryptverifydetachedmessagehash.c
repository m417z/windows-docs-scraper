BOOL CryptVerifyDetachedMessageHash(
  [in]      PCRYPT_HASH_MESSAGE_PARA pHashPara,
  [in]      BYTE                     *pbDetachedHashBlob,
  [in]      DWORD                    cbDetachedHashBlob,
  [in]      DWORD                    cToBeHashed,
  [in]      const BYTE * []          rgpbToBeHashed,
  [in]      DWORD []                 rgcbToBeHashed,
  [out]     BYTE                     *pbComputedHash,
  [in, out] DWORD                    *pcbComputedHash
);