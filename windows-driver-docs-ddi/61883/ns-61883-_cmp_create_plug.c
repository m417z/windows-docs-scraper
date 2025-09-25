typedef struct _CMP_CREATE_PLUG {
  IN CMP_PLUG_TYPE       PlugType;
  IN AV_PCR              Pcr;
  IN PCMP_NOTIFY_ROUTINE pfnNotify;
  IN PVOID               Context;
  OUT ULONG              PlugNum;
  OUT HANDLE             hPlug;
} CMP_CREATE_PLUG, *PCMP_CREATE_PLUG;