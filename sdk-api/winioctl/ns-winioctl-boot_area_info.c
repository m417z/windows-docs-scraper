typedef struct _BOOT_AREA_INFO {
  DWORD                    BootSectorCount;
  struct {
    LARGE_INTEGER Offset;
  } BootSectors[2];
} BOOT_AREA_INFO, *PBOOT_AREA_INFO;