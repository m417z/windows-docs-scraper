typedef struct _RASIKEV2_PROJECTION_INFO {
  DWORD       dwIPv4NegotiationError;
  RASIPV4ADDR ipv4Address;
  RASIPV4ADDR ipv4ServerAddress;
  DWORD       dwIPv6NegotiationError;
  RASIPV6ADDR ipv6Address;
  RASIPV6ADDR ipv6ServerAddress;
  DWORD       dwPrefixLength;
  DWORD       dwAuthenticationProtocol;
  DWORD       dwEapTypeId;
  DWORD       dwFlags;
  DWORD       dwEncryptionMethod;
  DWORD       numIPv4ServerAddresses;
  RASIPV4ADDR *ipv4ServerAddresses;
  DWORD       numIPv6ServerAddresses;
  RASIPV6ADDR *ipv6ServerAddresses;
} RASIKEV2_PROJECTION_INFO, *PRASIKEV2_PROJECTION_INFO;