BOOL CryptHashCertificate2(
  [in]      LPCWSTR    pwszCNGHashAlgid,
  [in]      DWORD      dwFlags,
            void       *pvReserved,
  [in]      const BYTE *pbEncoded,
  [in]      DWORD      cbEncoded,
  [out]     BYTE       *pbComputedHash,
  [in, out] DWORD      *pcbComputedHash
);