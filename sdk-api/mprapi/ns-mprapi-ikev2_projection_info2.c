typedef struct _IKEV2_PROJECTION_INFO2 {
  DWORD   dwIPv4NegotiationError;
  WCHAR   wszAddress[IPADDRESSLEN + 1];
  WCHAR   wszRemoteAddress[IPADDRESSLEN + 1];
  ULONG64 IPv4SubInterfaceIndex;
  DWORD   dwIPv6NegotiationError;
  BYTE    bInterfaceIdentifier[8];
  BYTE    bRemoteInterfaceIdentifier[8];
  BYTE    bPrefix[8];
  DWORD   dwPrefixLength;
  ULONG64 IPv6SubInterfaceIndex;
  DWORD   dwOptions;
  DWORD   dwAuthenticationProtocol;
  DWORD   dwEapTypeId;
  DWORD   dwEmbeddedEAPTypeId;
  DWORD   dwCompressionAlgorithm;
  DWORD   dwEncryptionMethod;
} IKEV2_PROJECTION_INFO2, *PIKEV2_PROJECTION_INFO2;