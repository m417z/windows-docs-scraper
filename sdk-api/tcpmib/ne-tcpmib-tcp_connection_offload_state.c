typedef enum {
  TcpConnectionOffloadStateInHost,
  TcpConnectionOffloadStateOffloading,
  TcpConnectionOffloadStateOffloaded,
  TcpConnectionOffloadStateUploading,
  TcpConnectionOffloadStateMax
} TCP_CONNECTION_OFFLOAD_STATE, *PTCP_CONNECTION_OFFLOAD_STATE;