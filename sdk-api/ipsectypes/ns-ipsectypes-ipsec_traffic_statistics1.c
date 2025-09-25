typedef struct IPSEC_TRAFFIC_STATISTICS1_ {
  UINT64 encryptedByteCount;
  UINT64 authenticatedAHByteCount;
  UINT64 authenticatedESPByteCount;
  UINT64 transportByteCount;
  UINT64 tunnelByteCount;
  UINT64 offloadByteCount;
  UINT64 totalSuccessfulPackets;
} IPSEC_TRAFFIC_STATISTICS1;