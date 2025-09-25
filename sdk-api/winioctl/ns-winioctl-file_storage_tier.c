typedef struct _FILE_STORAGE_TIER {
  GUID                         Id;
  WCHAR                        Name[FILE_STORAGE_TIER_NAME_LENGTH];
  WCHAR                        Description[FILE_STORAGE_TIER_NAME_LENGTH];
  DWORDLONG                    Flags;
  DWORDLONG                    ProvisionedCapacity;
  FILE_STORAGE_TIER_MEDIA_TYPE MediaType;
  FILE_STORAGE_TIER_CLASS      Class;
} FILE_STORAGE_TIER, *PFILE_STORAGE_TIER;