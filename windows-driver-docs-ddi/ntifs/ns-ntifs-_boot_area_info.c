typedef struct _BOOT_AREA_INFO {
  ULONG                    BootSectorCount;
  struct {
    LARGE_INTEGER Offset;
  };
  __unnamed_struct_00b5_70 BootSectors[2];
} BOOT_AREA_INFO, *PBOOT_AREA_INFO;