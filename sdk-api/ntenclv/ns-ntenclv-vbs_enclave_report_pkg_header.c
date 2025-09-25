typedef struct VBS_ENCLAVE_REPORT_PKG_HEADER {
  UINT32 PackageSize;
  UINT32 Version;
  UINT32 SignatureScheme;
  UINT32 SignedStatementSize;
  UINT32 SignatureSize;
  UINT32 Reserved;
} VBS_ENCLAVE_REPORT_PKG_HEADER;