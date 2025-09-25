typedef enum {
  TcpErrorNone = 0,
  TcpErrorBelowDataWindow,
  TcpErrorAboveDataWindow,
  TcpErrorBelowAckWindow,
  TcpErrorAboveAckWindow,
  TcpErrorBelowTsWindow,
  TcpErrorAboveTsWindow,
  TcpErrorDataChecksumError,
  TcpErrorDataLengthError,
  TcpErrorMaxSoftError
} TCP_SOFT_ERROR, *PTCP_SOFT_ERROR;