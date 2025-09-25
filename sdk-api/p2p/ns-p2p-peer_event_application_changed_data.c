typedef struct peer_event_application_changed_data_tag {
  PPEER_CONTACT     pContact;
  PPEER_ENDPOINT    pEndpoint;
  PEER_CHANGE_TYPE  changeType;
  PPEER_APPLICATION pApplication;
} PEER_EVENT_APPLICATION_CHANGED_DATA, *PPEER_EVENT_APPLICATION_CHANGED_DATA;