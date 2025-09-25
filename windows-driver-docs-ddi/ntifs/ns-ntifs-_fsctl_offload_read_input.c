typedef struct _FSCTL_OFFLOAD_READ_INPUT {
  ULONG     Size;
  ULONG     Flags;
  ULONG     TokenTimeToLive;
  ULONG     Reserved;
  ULONGLONG FileOffset;
  ULONGLONG CopyLength;
} FSCTL_OFFLOAD_READ_INPUT, *PFSCTL_OFFLOAD_READ_INPUT;