typedef struct _MIB_UDP6ROW {
  IN6_ADDR dwLocalAddr;
  DWORD    dwLocalScopeId;
  DWORD    dwLocalPort;
} MIB_UDP6ROW, *PMIB_UDP6ROW;