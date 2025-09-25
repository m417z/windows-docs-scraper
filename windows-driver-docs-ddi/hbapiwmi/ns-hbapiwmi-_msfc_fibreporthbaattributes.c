typedef struct _MSFC_FibrePortHBAAttributes {
  ULONGLONG                     UniquePortId;
  ULONG                         HBAStatus;
  MSFC_HBAPortAttributesResults Attributes;
} MSFC_FibrePortHBAAttributes, *PMSFC_FibrePortHBAAttributes;