typedef struct VBS_ENCLAVE_REPORT_MODULE {
  VBS_ENCLAVE_REPORT_VARDATA_HEADER Header;
  UINT8                             UniqueId[IMAGE_ENCLAVE_LONG_ID_LENGTH];
  UINT8                             AuthorId[IMAGE_ENCLAVE_LONG_ID_LENGTH];
  UINT8                             FamilyId[IMAGE_ENCLAVE_SHORT_ID_LENGTH];
  UINT8                             ImageId[IMAGE_ENCLAVE_SHORT_ID_LENGTH];
  UINT32                            Svn;
  WCHAR                             ModuleName[ANYSIZE_ARRAY];
} VBS_ENCLAVE_REPORT_MODULE;