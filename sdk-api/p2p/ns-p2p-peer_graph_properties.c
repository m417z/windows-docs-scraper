typedef struct peer_graph_properties_tag {
  DWORD dwSize;
  DWORD dwFlags;
  DWORD dwScope;
  DWORD dwMaxRecordSize;
  PWSTR pwzGraphId;
  PWSTR pwzCreatorId;
  PWSTR pwzFriendlyName;
  PWSTR pwzComment;
  ULONG ulPresenceLifetime;
  ULONG cPresenceMax;
} PEER_GRAPH_PROPERTIES, *PPEER_GRAPH_PROPERTIES;