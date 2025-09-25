typedef struct _IDE_LBA_RANGE {
  ULONGLONG StartSector : 48;
  ULONGLONG SectorCount : 16;
} IDE_LBA_RANGE, *PIDE_LBA_RANGE;