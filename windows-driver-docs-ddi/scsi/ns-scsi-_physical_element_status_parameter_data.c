typedef struct _PHYSICAL_ELEMENT_STATUS_PARAMETER_DATA {
  UCHAR                                   DescriptorCount[4];
  UCHAR                                   ReturnedDescriptorCount[4];
  UCHAR                                   ElementIdentifierBeingDepoped[4];
  UCHAR                                   Reserved[20];
  PHYSICAL_ELEMENT_STATUS_DATA_DESCRIPTOR Descriptors[ANYSIZE_ARRAY];
} PHYSICAL_ELEMENT_STATUS_PARAMETER_DATA, *PPHYSICAL_ELEMENT_STATUS_PARAMETER_DATA;