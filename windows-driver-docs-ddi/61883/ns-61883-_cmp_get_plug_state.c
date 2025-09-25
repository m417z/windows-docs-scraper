typedef struct _CMP_GET_PLUG_STATE {
  IN HANDLE hPlug;
  OUT ULONG State;
  OUT ULONG DataRate;
  OUT ULONG Payload;
  OUT ULONG BC_Connections;
  OUT ULONG PP_Connections;
} CMP_GET_PLUG_STATE, *PCMP_GET_PLUG_STATE;