typedef struct _WTS_USER_DATA {
  WCHAR                     WorkDirectory[WTS_DIRECTORY_LENGTH + 1];
  WCHAR                     InitialProgram[WTS_INITIALPROGRAM_LENGTH + 1];
  WTS_TIME_ZONE_INFORMATION UserTimeZone;
} WTS_USER_DATA, *PWTS_USER_DATA;