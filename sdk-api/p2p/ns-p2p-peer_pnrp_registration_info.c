typedef struct peer_pnrp_registration_info_tag {
  PWSTR     pwzCloudName;
  PWSTR     pwzPublishingIdentity;
  ULONG     cAddresses;
  SOCKADDR  **ppAddresses;
  WORD      wPort;
  PWSTR     pwzComment;
  PEER_DATA payload;
} PEER_PNRP_REGISTRATION_INFO, *PPEER_PNRP_REGISTRATION_INFO;