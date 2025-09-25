typedef struct _PHYSICAL_ELEMENT_STATUS {
  ULONG                              Version;
  ULONG                              Size;
  ULONG                              DescriptorCount;
  ULONG                              ReturnedDescriptorCount;
  ULONG                              ElementIdentifierBeingDepoped;
  ULONG                              Reserved;
  PHYSICAL_ELEMENT_STATUS_DESCRIPTOR Descriptors[ANYSIZE_ARRAY];
} PHYSICAL_ELEMENT_STATUS, *PPHYSICAL_ELEMENT_STATUS;