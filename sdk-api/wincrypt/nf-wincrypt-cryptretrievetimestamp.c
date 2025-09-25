BOOL CryptRetrieveTimeStamp(
  [in]            LPCWSTR                    wszUrl,
                  DWORD                      dwRetrievalFlags,
                  DWORD                      dwTimeout,
  [in]            LPCSTR                     pszHashId,
  [in, optional]  const CRYPT_TIMESTAMP_PARA *pPara,
  [in]            const BYTE                 *pbData,
                  DWORD                      cbData,
  [out]           PCRYPT_TIMESTAMP_CONTEXT   *ppTsContext,
  [out, optional] PCCERT_CONTEXT             *ppTsSigner,
  [out, optional] HCERTSTORE                 *phStore
);