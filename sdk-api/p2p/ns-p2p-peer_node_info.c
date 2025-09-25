typedef struct peer_node_info_tag {
  DWORD         dwSize;
  ULONGLONG     ullNodeId;
  PWSTR         pwzPeerId;
  ULONG         cAddresses;
  PPEER_ADDRESS pAddresses;
  PWSTR         pwzAttributes;
} PEER_NODE_INFO, *PPEER_NODE_INFO;