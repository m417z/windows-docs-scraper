typedef struct _ACX_TARGET_STREAM_CONFIG {
  ULONG            Size;
  ULONG            Flags;
  ACXTARGETCIRCUIT TargetCircuit;
  ULONG            PinId;
  ACXDATAFORMAT    DataFormat;
  PCGUID           SignalProcessingMode;
  ACXOBJECTBAG     OptionalParameters;
} ACX_TARGET_STREAM_CONFIG, *PACX_TARGET_STREAM_CONFIG;