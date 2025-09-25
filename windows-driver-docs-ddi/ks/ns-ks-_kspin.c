typedef struct _KSPIN {
  const KSPIN_DESCRIPTOR_EX *Descriptor;
  KSOBJECT_BAG              Bag;
  PVOID                     Context;
  ULONG                     Id;
  KSPIN_COMMUNICATION       Communication;
  BOOLEAN                   ConnectionIsExternal;
  KSPIN_INTERFACE           ConnectionInterface;
  KSPIN_MEDIUM              ConnectionMedium;
  KSPRIORITY                ConnectionPriority;
  PKSDATAFORMAT             ConnectionFormat;
  PKSMULTIPLE_ITEM          AttributeList;
  ULONG                     StreamHeaderSize;
  KSPIN_DATAFLOW            DataFlow;
  KSSTATE                   DeviceState;
  KSRESET                   ResetState;
  KSSTATE                   ClientState;
} KSPIN, *PKSPIN;