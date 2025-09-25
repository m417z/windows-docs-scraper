typedef struct peer_connection_info_tag {
  DWORD        dwSize;
  DWORD        dwFlags;
  ULONGLONG    ullConnectionId;
  ULONGLONG    ullNodeId;
  PWSTR        pwzPeerId;
  PEER_ADDRESS address;
} PEER_CONNECTION_INFO;