typedef struct {
  ULONG                 InterfacesCount;
  const KSPIN_INTERFACE *Interfaces;
  ULONG                 MediumsCount;
  const KSPIN_MEDIUM    *Mediums;
  ULONG                 DataRangesCount;
  const PKSDATARANGE    *DataRanges;
  KSPIN_DATAFLOW        DataFlow;
  KSPIN_COMMUNICATION   Communication;
  const GUID            *Category;
  const GUID            *Name;
  union {
    LONGLONG Reserved;
    struct {
      ULONG        ConstrainedDataRangesCount;
      PKSDATARANGE *ConstrainedDataRanges;
    };
  };
} KSPIN_DESCRIPTOR, *PKSPIN_DESCRIPTOR;