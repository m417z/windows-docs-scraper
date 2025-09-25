typedef struct _PHYSICAL_ELEMENT_STATUS_DESCRIPTOR {
  ULONG     Version;
  ULONG     Size;
  ULONG     ElementIdentifier;
  UCHAR     PhysicalElementType;
  UCHAR     PhysicalElementHealth;
  UCHAR     Reserved1[2];
  ULONGLONG AssociatedCapacity;
  ULONG     Reserved2[4];
} PHYSICAL_ELEMENT_STATUS_DESCRIPTOR, *PPHYSICAL_ELEMENT_STATUS_DESCRIPTOR;