typedef struct peer_group_event_data_tag {
  PEER_GROUP_EVENT_TYPE eventType;
  union {
    PEER_GROUP_STATUS                 dwStatus;
    PEER_EVENT_INCOMING_DATA          incomingData;
    PEER_EVENT_RECORD_CHANGE_DATA     recordChangeData;
    PEER_EVENT_CONNECTION_CHANGE_DATA connectionChangeData;
    PEER_EVENT_MEMBER_CHANGE_DATA     memberChangeData;
    HRESULT                           hrConnectionFailedReason;
  };
} PEER_GROUP_EVENT_DATA, *PPEER_GROUP_EVENT_DATA;