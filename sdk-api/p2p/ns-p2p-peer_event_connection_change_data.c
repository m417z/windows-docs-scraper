typedef struct peer_event_connection_change_data_tag {
  DWORD                  dwSize;
  PEER_CONNECTION_STATUS status;
  ULONGLONG              ullConnectionId;
  ULONGLONG              ullNodeId;
  ULONGLONG              ullNextConnectionId;
  HRESULT                hrConnectionFailedReason;
} PEER_EVENT_CONNECTION_CHANGE_DATA, *PPEER_EVENT_CONNECTION_CHANGE_DATA;