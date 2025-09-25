typedef struct _CM_RESOURCE_LIST {
  ULONG                       Count;
  CM_FULL_RESOURCE_DESCRIPTOR List[1];
} CM_RESOURCE_LIST, *PCM_RESOURCE_LIST;