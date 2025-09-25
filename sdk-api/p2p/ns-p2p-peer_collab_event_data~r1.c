typedef struct peer_collab_event_data_tag {
  PEER_COLLAB_EVENT_TYPE eventType;
  union {
    PEER_EVENT_WATCHLIST_CHANGED_DATA      watchListChangedData;
    PEER_EVENT_PRESENCE_CHANGED_DATA       presenceChangedData;
    PEER_EVENT_APPLICATION_CHANGED_DATA    applicationChangedData;
    PEER_EVENT_OBJECT_CHANGED_DATA         objectChangedData;
    PEER_EVENT_ENDPOINT_CHANGED_DATA       endpointChangedData;
    PEER_EVENT_PEOPLE_NEAR_ME_CHANGED_DATA peopleNearMeChangedData;
    PEER_EVENT_REQUEST_STATUS_CHANGED_DATA requestStatusChangedData;
  };
} PEER_COLLAB_EVENT_DATA, *PPEER_COLLAB_EVENT_DATA;