typedef struct _WHEA_ACPI_HEADER {
  UINT32 Signature;
  UINT32 Length;
  UINT8  Revision;
  UINT8  Checksum;
  UINT8  OemId[6];
  UINT64 OemTableId;
  UINT32 OemRevision;
  UINT32 CreatorId;
  UINT32 CreatorRevision;
} WHEA_ACPI_HEADER, *PWHEA_ACPI_HEADER;