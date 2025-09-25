typedef struct _KEY_VIRTUALIZATION_INFORMATION {
  ULONG VirtualizationCandidate : 1;
  ULONG VirtualizationEnabled : 1;
  ULONG VirtualTarget : 1;
  ULONG VirtualStore : 1;
  ULONG VirtualSource : 1;
  ULONG Reserved : 27;
} KEY_VIRTUALIZATION_INFORMATION, *PKEY_VIRTUALIZATION_INFORMATION;