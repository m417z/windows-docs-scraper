typedef struct _ACPI_PDTT {
  DESCRIPTION_HEADER Header;
  UCHAR              TriggerCount;
  UCHAR              Reserved[3];
  ULONG              TriggerOffset;
} ACPI_PDTT, *PACPI_PDTT;