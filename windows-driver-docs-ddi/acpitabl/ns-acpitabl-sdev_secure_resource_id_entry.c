typedef struct _SDEV_SECURE_RESOURCE_ID_ENTRY {
  SDEV_ENTRY_HEADER Header;
  USHORT            HardwareIdentifierOffset;
  USHORT            HardwareIdentifierLength;
  USHORT            SubsystemIdentifierOffset;
  USHORT            SubsystemIdentifierLength;
  USHORT            HardwareRevision;
  UCHAR             HardwareRevisionPresent;
} SDEV_SECURE_RESOURCE_ID_ENTRY, *PSDEV_SECURE_RESOURCE_ID_ENTRY;