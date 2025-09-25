typedef struct _SAFER_IDENTIFICATION_HEADER {
  SAFER_IDENTIFICATION_TYPES dwIdentificationType;
  DWORD                      cbStructSize;
  GUID                       IdentificationGuid;
  FILETIME                   lastModified;
} SAFER_IDENTIFICATION_HEADER, *PSAFER_IDENTIFICATION_HEADER;