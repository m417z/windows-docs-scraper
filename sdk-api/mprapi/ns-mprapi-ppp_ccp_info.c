typedef struct _PPP_CCP_INFO {
  DWORD dwError;
  DWORD dwCompressionAlgorithm;
  DWORD dwOptions;
  DWORD dwRemoteCompressionAlgorithm;
  DWORD dwRemoteOptions;
} PPP_CCP_INFO;