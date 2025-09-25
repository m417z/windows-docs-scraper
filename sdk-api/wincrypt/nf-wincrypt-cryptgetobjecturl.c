BOOL CryptGetObjectUrl(
  [in]      LPCSTR           pszUrlOid,
  [in]      LPVOID           pvPara,
  [in]      DWORD            dwFlags,
  [out]     PCRYPT_URL_ARRAY pUrlArray,
  [in, out] DWORD            *pcbUrlArray,
  [out]     PCRYPT_URL_INFO  pUrlInfo,
  [in, out] DWORD            *pcbUrlInfo,
            LPVOID           pvReserved
);