typedef struct _WIM_PROVIDER_OVERLAY_ENTRY {
  ULONG         NextEntryOffset;
  LARGE_INTEGER DataSourceId;
  GUID          WimGuid;
  ULONG         WimFileNameOffset;
  ULONG         WimType;
  ULONG         WimIndex;
  ULONG         Flags;
} WIM_PROVIDER_OVERLAY_ENTRY, *PWIM_PROVIDER_OVERLAY_ENTRY;