typedef struct _IMAGE_ENCLAVE_CONFIG64 {
  DWORD     Size;
  DWORD     MinimumRequiredConfigSize;
  DWORD     PolicyFlags;
  DWORD     NumberOfImports;
  DWORD     ImportList;
  DWORD     ImportEntrySize;
  BYTE      FamilyID[IMAGE_ENCLAVE_SHORT_ID_LENGTH];
  BYTE      ImageID[IMAGE_ENCLAVE_SHORT_ID_LENGTH];
  DWORD     ImageVersion;
  DWORD     SecurityVersion;
  ULONGLONG EnclaveSize;
  DWORD     NumberOfThreads;
  DWORD     EnclaveFlags;
} IMAGE_ENCLAVE_CONFIG64, *PIMAGE_ENCLAVE_CONFIG64;