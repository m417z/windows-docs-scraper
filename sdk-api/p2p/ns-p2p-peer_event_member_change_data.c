typedef struct peer_event_member_change_data_tag {
  DWORD                   dwSize;
  PEER_MEMBER_CHANGE_TYPE changeType;
  PWSTR                   pwzIdentity;
} PEER_EVENT_MEMBER_CHANGE_DATA, *PPEER_EVENT_MEMBER_CHANGE_DATA;