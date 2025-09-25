BOOL CryptGetAsyncParam(
  HCRYPTASYNC                     hAsync,
  LPSTR                           pszParamOid,
  LPVOID                          *ppvParam,
  PFN_CRYPT_ASYNC_PARAM_FREE_FUNC *ppfnFree
);