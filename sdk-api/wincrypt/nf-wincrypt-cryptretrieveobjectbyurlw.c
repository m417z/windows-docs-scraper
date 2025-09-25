BOOL CryptRetrieveObjectByUrlW(
  [in]           LPCWSTR                  pszUrl,
  [in]           LPCSTR                   pszObjectOid,
  [in]           DWORD                    dwRetrievalFlags,
  [in]           DWORD                    dwTimeout,
  [out]          LPVOID                   *ppvObject,
  [in]           HCRYPTASYNC              hAsyncRetrieve,
  [in, optional] PCRYPT_CREDENTIALS       pCredentials,
  [in, optional] LPVOID                   pvVerify,
  [in]           PCRYPT_RETRIEVE_AUX_INFO pAuxInfo
);