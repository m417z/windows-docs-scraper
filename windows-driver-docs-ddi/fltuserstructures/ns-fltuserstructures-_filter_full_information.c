typedef struct _FILTER_FULL_INFORMATION {
  ULONG  NextEntryOffset;
  ULONG  FrameID;
  ULONG  NumberOfInstances;
  USHORT FilterNameLength;
  WCHAR  FilterNameBuffer[1];
} FILTER_FULL_INFORMATION, *PFILTER_FULL_INFORMATION;