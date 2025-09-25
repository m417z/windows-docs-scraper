typedef struct {
  KSPROPERTY Property;
  ULONG      PinId;
  ULONG      NodeId;
  ULONG      Flags;
  ULONG      Reserved;
} SYSAUDIO_SELECT_GRAPH, *PSYSAUDIO_SELECT_GRAPH;