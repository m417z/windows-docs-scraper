typedef struct _SAFER_PATHNAME_IDENTIFICATION {
  SAFER_IDENTIFICATION_HEADER header;
  WCHAR                       Description[SAFER_MAX_DESCRIPTION_SIZE];
  PWCHAR                      ImageName;
  DWORD                       dwSaferFlags;
} SAFER_PATHNAME_IDENTIFICATION, *PSAFER_PATHNAME_IDENTIFICATION;