typedef struct _CMP_MONITOR_PLUGS {
  IN ULONG                Flags;
  IN PCMP_MONITOR_ROUTINE pfnNotify;
  IN PVOID                Context;
} CMP_MONITOR_PLUGS, *PCMP_MONITOR_PLUGS;