typedef struct peer_event_node_change_data_tag {
  DWORD                 dwSize;
  PEER_NODE_CHANGE_TYPE changeType;
  ULONGLONG             ullNodeId;
  PWSTR                 pwzPeerId;
} PEER_EVENT_NODE_CHANGE_DATA, *PPEER_EVENT_NODE_CHANGE_DATA;