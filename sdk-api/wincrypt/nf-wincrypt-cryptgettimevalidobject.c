BOOL CryptGetTimeValidObject(
  [in]                LPCSTR                                  pszTimeValidOid,
  [in]                LPVOID                                  pvPara,
  [in]                PCCERT_CONTEXT                          pIssuer,
  [in, optional]      LPFILETIME                              pftValidFor,
  [in]                DWORD                                   dwFlags,
  [in]                DWORD                                   dwTimeout,
  [out, optional]     LPVOID                                  *ppvObject,
  [in, optional]      PCRYPT_CREDENTIALS                      pCredentials,
  [in, out, optional] PCRYPT_GET_TIME_VALID_OBJECT_EXTRA_INFO pExtraInfo
);