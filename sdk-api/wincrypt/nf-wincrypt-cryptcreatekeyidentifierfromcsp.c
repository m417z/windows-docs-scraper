BOOL CryptCreateKeyIdentifierFromCSP(
  [in]      DWORD                dwCertEncodingType,
  [in]      LPCSTR               pszPubKeyOID,
  [in]      const PUBLICKEYSTRUC *pPubKeyStruc,
  [in]      DWORD                cbPubKeyStruc,
  [in]      DWORD                dwFlags,
  [in]      void                 *pvReserved,
  [out]     BYTE                 *pbHash,
  [in, out] DWORD                *pcbHash
);