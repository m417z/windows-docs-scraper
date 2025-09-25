typedef struct _MPIO_DRIVE_INFO {
  ULONG NumberPaths;
  WCHAR Name[63 + 1];
  WCHAR SerialNumber[63 + 1];
  WCHAR DsmName[63 + 1];
} MPIO_DRIVE_INFO, *PMPIO_DRIVE_INFO;