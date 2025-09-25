typedef struct peer_event_incoming_data_tag {
  DWORD     dwSize;
  ULONGLONG ullConnectionId;
  GUID      type;
  PEER_DATA data;
} PEER_EVENT_INCOMING_DATA, *PPEER_EVENT_INCOMING_DATA;