typedef struct peer_event_record_change_data_tag {
  DWORD                   dwSize;
  PEER_RECORD_CHANGE_TYPE changeType;
  GUID                    recordId;
  GUID                    recordType;
} PEER_EVENT_RECORD_CHANGE_DATA, *PPEER_EVENT_RECORD_CHANGE_DATA;