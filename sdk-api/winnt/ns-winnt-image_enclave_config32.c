typedef struct _IMAGE_ENCLAVE_CONFIG32 {
  DWORD Size;
  DWORD MinimumRequiredConfigSize;
  DWORD PolicyFlags;
  DWORD NumberOfImports;
  DWORD ImportList;
  DWORD ImportEntrySize;
  BYTE  FamilyID[IMAGE_ENCLAVE_SHORT_ID_LENGTH];
  BYTE  ImageID[IMAGE_ENCLAVE_SHORT_ID_LENGTH];
  DWORD ImageVersion;
  DWORD SecurityVersion;
  DWORD EnclaveSize;
  DWORD NumberOfThreads;
  DWORD EnclaveFlags;
} IMAGE_ENCLAVE_CONFIG32, *PIMAGE_ENCLAVE_CONFIG32;