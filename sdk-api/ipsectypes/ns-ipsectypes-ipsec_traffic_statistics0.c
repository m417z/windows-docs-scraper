typedef struct IPSEC_TRAFFIC_STATISTICS0_ {
  UINT64 encryptedByteCount;
  UINT64 authenticatedAHByteCount;
  UINT64 authenticatedESPByteCount;
  UINT64 transportByteCount;
  UINT64 tunnelByteCount;
  UINT64 offloadByteCount;
} IPSEC_TRAFFIC_STATISTICS0;