typedef struct _PDO_INFORMATION {
  PDOSCSI_ADDR ScsiAddress;
  ULONG        DeviceState;
  ULONGLONG    PathIdentifier;
  ULONG        IdentifierType;
  ULONG        IdentifierLength;
  UCHAR        Identifier[32];
  UCHAR        Pad[4];
} PDO_INFORMATION, *PPDO_INFORMATION;