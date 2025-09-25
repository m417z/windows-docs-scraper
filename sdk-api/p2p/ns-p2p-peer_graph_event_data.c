typedef struct peer_graph_event_data_tag {
  PEER_GRAPH_EVENT_TYPE eventType;
  union {
    PEER_GRAPH_STATUS_FLAGS           dwStatus;
    PEER_EVENT_INCOMING_DATA          incomingData;
    PEER_EVENT_RECORD_CHANGE_DATA     recordChangeData;
    PEER_EVENT_CONNECTION_CHANGE_DATA connectionChangeData;
    PEER_EVENT_NODE_CHANGE_DATA       nodeChangeData;
    PEER_EVENT_SYNCHRONIZED_DATA      synchronizedData;
  };
} PEER_GRAPH_EVENT_DATA, *PPEER_GRAPH_EVENT_DATA;