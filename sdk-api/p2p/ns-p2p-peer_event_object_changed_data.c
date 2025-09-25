typedef struct peer_event_object_changed_data_tag {
  PPEER_CONTACT    pContact;
  PPEER_ENDPOINT   pEndpoint;
  PEER_CHANGE_TYPE changeType;
  PPEER_OBJECT     pObject;
} PEER_EVENT_OBJECT_CHANGED_DATA, *PPEER_EVENT_OBJECT_CHANGED_DATA;