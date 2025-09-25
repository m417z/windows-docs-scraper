typedef struct _WHEA_DRIVER_BUFFER_SET {
  ULONG  Version;
  PUCHAR Data;
  ULONG  DataSize;
  LPGUID SectionTypeGuid;
  PUCHAR SectionFriendlyName;
  PUCHAR Flags;
} WHEA_DRIVER_BUFFER_SET, *PWHEA_DRIVER_BUFFER_SET;