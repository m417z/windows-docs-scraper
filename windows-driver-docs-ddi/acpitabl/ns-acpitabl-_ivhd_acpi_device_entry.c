typedef struct _IVHD_ACPI_DEVICE_ENTRY {
  UINT8  Type;
  UINT16 DeviceId;
  union {
    UINT8 AsUINT8;
    struct {
      UINT8 INITPass : 1;
      UINT8 ExtIntPass : 1;
      UINT8 NMIPass : 1;
      UINT8 ReservedZ0 : 1;
      UINT8 SysMgt : 2;
      UINT8 LINT0Pass : 1;
      UINT8 LINT1Pass : 1;
    } DUMMYSTRUCTNAME;
  } DataSetting;
  UINT64 HardwareId;
  UINT64 CompatibleId;
  UINT8  UniqueIdFormat;
  UINT8  UniqueIdLength;
} IVHD_ACPI_DEVICE_ENTRY, *PIVHD_ACPI_DEVICE_ENTRY;