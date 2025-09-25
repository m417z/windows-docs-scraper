typedef struct peer_event_presence_changed_data_tag {
  PPEER_CONTACT       pContact;
  PPEER_ENDPOINT      pEndpoint;
  PEER_CHANGE_TYPE    changeType;
  PPEER_PRESENCE_INFO pPresenceInfo;
} PEER_EVENT_PRESENCE_CHANGED_DATA, *PPEER_EVENT_PRESENCE_CHANGED_DATA;