typedef struct _SecPkgCredentials_SSIProviderW {
  SEC_WCHAR     *sProviderName;
  unsigned long ProviderInfoLength;
  char          *ProviderInfo;
} SecPkgCredentials_SSIProviderW, *PSecPkgCredentials_SSIProviderW;