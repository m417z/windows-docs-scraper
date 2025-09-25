typedef struct peer_collab_event_registration_tag {
  PEER_COLLAB_EVENT_TYPE eventType;
  GUID                   *pInstance;
} PEER_COLLAB_EVENT_REGISTRATION, *PPEER_COLLAB_EVENT_REGISTRATION;