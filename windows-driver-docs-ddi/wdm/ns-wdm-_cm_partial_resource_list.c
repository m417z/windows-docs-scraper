typedef struct _CM_PARTIAL_RESOURCE_LIST {
  USHORT                         Version;
  USHORT                         Revision;
  ULONG                          Count;
  CM_PARTIAL_RESOURCE_DESCRIPTOR PartialDescriptors[1];
} CM_PARTIAL_RESOURCE_LIST, *PCM_PARTIAL_RESOURCE_LIST;