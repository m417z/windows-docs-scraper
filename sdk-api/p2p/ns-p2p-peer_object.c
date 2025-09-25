typedef struct peer_object_tag {
  GUID      id;
  PEER_DATA data;
  DWORD     dwPublicationScope;
} PEER_OBJECT, *PPEER_OBJECT;