BOOL CryptSetAsyncParam(
  HCRYPTASYNC                     hAsync,
  LPSTR                           pszParamOid,
  LPVOID                          pvParam,
  PFN_CRYPT_ASYNC_PARAM_FREE_FUNC pfnFree
);