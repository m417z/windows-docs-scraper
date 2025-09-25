typedef struct _HW_STREAM_INFORMATION {
  ULONG              NumberOfPossibleInstances;
  KSPIN_DATAFLOW     DataFlow;
  BOOLEAN            DataAccessible;
  ULONG              NumberOfFormatArrayEntries;
  PKSDATAFORMAT      *StreamFormatsArray;
  PVOID              ClassReserved[4];
  ULONG              NumStreamPropArrayEntries;
  PKSPROPERTY_SET    StreamPropertiesArray;
  ULONG              NumStreamEventArrayEntries;
  PKSEVENT_SET       StreamEventsArray;
  GUID               *Category;
  GUID               *Name;
  ULONG              MediumsCount;
  const KSPIN_MEDIUM *Mediums;
  BOOLEAN            BridgeStream;
  ULONG              Reserved[2];
} HW_STREAM_INFORMATION, *PHW_STREAM_INFORMATION;