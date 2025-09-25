typedef struct peer_graph_event_registration_tag {
  PEER_GRAPH_EVENT_TYPE eventType;
  GUID                  *pType;
} PEER_GRAPH_EVENT_REGISTRATION, *PPEER_GRAPH_EVENT_REGISTRATION;