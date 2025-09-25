typedef struct tACMFORMATDETAILS {
  DWORD          cbStruct;
  DWORD          dwFormatIndex;
  DWORD          dwFormatTag;
  DWORD          fdwSupport;
  LPWAVEFORMATEX pwfx;
  DWORD          cbwfx;
  char           szFormat[ACMFORMATDETAILS_FORMAT_CHARS];
} ACMFORMATDETAILS, *PACMFORMATDETAILS, *LPACMFORMATDETAILS;