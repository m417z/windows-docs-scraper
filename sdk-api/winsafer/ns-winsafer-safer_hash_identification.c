typedef struct _SAFER_HASH_IDENTIFICATION {
  SAFER_IDENTIFICATION_HEADER header;
  WCHAR                       Description[SAFER_MAX_DESCRIPTION_SIZE];
  WCHAR                       FriendlyName[SAFER_MAX_FRIENDLYNAME_SIZE];
  DWORD                       HashSize;
  BYTE                        ImageHash[SAFER_MAX_HASH_SIZE];
  ALG_ID                      HashAlgorithm;
  LARGE_INTEGER               ImageSize;
  DWORD                       dwSaferFlags;
} SAFER_HASH_IDENTIFICATION, *PSAFER_HASH_IDENTIFICATION;