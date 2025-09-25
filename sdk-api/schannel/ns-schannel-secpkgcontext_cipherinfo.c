typedef struct _SecPkgContext_CipherInfo {
  DWORD dwVersion;
  DWORD dwProtocol;
  DWORD dwCipherSuite;
  DWORD dwBaseCipherSuite;
  WCHAR szCipherSuite[SZ_ALG_MAX_SIZE];
  WCHAR szCipher[SZ_ALG_MAX_SIZE];
  DWORD dwCipherLen;
  DWORD dwCipherBlockLen;
  WCHAR szHash[SZ_ALG_MAX_SIZE];
  DWORD dwHashLen;
  WCHAR szExchange[SZ_ALG_MAX_SIZE];
  DWORD dwMinExchangeLen;
  DWORD dwMaxExchangeLen;
  WCHAR szCertificate[SZ_ALG_MAX_SIZE];
  DWORD dwKeyType;
} SecPkgContext_CipherInfo, *PSecPkgContext_CipherInfo;