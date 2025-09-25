typedef struct peer_pnrp_endpoint_info_tag {
  PWSTR     pwzPeerName;
  ULONG     cAddresses;
  SOCKADDR  **ppAddresses;
  PWSTR     pwzComment;
  PEER_DATA payload;
} PEER_PNRP_ENDPOINT_INFO, *PPEER_PNRP_ENDPOINT_INFO;