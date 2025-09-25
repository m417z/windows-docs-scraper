typedef struct _ACX_STREAM_BRIDGE_CONFIG {
  ULONG                  Size;
  ULONG                  Flags;
  ACX_STREAM_BRIDGE_TYPE Type;
  ULONG                  InModesCount;
  PCGUID                 *InModes;
  PCGUID                 OutMode;
  ACXOBJECTBAG           OutStreamVarArguments;
  WDF_OBJECT_ATTRIBUTES  TargetStreamAttributes;
} ACX_STREAM_BRIDGE_CONFIG, *PACX_STREAM_BRIDGE_CONFIG;