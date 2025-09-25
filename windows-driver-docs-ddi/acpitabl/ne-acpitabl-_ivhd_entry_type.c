typedef enum _IVHD_ENTRY_TYPE {
  IvhdEntryTypePad4,
  IvhdEntryTypeAll,
  IvhdEntryTypeSelect,
  IvhdEntryTypeStartRange,
  IvhdEntryTypeEndRange,
  IvhdEntryTypePad8,
  IvhdEntryTypeAliasSelect,
  IvhdEntryTypeAliasStartRange,
  IvhdEntryTypeExtendedSelect,
  IvhdEntryTypeExtendedStartRange,
  IvhdEntryTypeSpecialDevice,
  IvhdEntryTypeAcpiDevice
} IVRS_TABLE_TYPE;