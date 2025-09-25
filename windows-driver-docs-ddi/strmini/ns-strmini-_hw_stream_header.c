typedef struct _HW_STREAM_HEADER {
  ULONG             NumberOfStreams;
  ULONG             SizeOfHwStreamInformation;
  ULONG             NumDevPropArrayEntries;
  PKSPROPERTY_SET   DevicePropertiesArray;
  ULONG             NumDevEventArrayEntries;
  PKSEVENT_SET      DeviceEventsArray;
  PKSTOPOLOGY       Topology;
  PHW_EVENT_ROUTINE DeviceEventRoutine;
  LONG              NumDevMethodArrayEntries;
  PKSMETHOD_SET     DeviceMethodsArray;
  ULONG             Reserved[2];
} HW_STREAM_HEADER, *PHW_STREAM_HEADER;