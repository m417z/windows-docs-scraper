typedef struct _PHYSICAL_ELEMENT_STATUS_DATA_DESCRIPTOR {
  UCHAR Reserved1[4];
  UCHAR ElementIdentifier[4];
  UCHAR Reserved2[6];
  UCHAR PhysicalElementType;
  UCHAR PhysicalElementHealth;
  UCHAR AssociatedCapacity[8];
  UCHAR Reserved3[8];
} PHYSICAL_ELEMENT_STATUS_DATA_DESCRIPTOR, *PPHYSICAL_ELEMENT_STATUS_DATA_DESCRIPTOR;