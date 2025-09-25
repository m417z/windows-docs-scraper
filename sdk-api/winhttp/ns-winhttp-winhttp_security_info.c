typedef struct _WINHTTP_SECURITY_INFO {
  SecPkgContext_ConnectionInfo ConnectionInfo;
  SecPkgContext_CipherInfo     CipherInfo;
} WINHTTP_SECURITY_INFO, *PWINHTTP_SECURITY_INFO;