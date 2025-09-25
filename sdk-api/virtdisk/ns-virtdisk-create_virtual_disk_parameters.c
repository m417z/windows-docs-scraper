typedef struct _CREATE_VIRTUAL_DISK_PARAMETERS {
  CREATE_VIRTUAL_DISK_VERSION Version;
  union {
    struct {
      GUID      UniqueId;
      ULONGLONG MaximumSize;
      ULONG     BlockSizeInBytes;
      ULONG     SectorSizeInBytes;
      PCWSTR    ParentPath;
      PCWSTR    SourcePath;
    } Version1;
    struct {
      GUID                   UniqueId;
      ULONGLONG              MaximumSize;
      ULONG                  BlockSizeInBytes;
      ULONG                  SectorSizeInBytes;
      ULONG                  PhysicalSectorSizeInBytes;
      PCWSTR                 ParentPath;
      PCWSTR                 SourcePath;
      OPEN_VIRTUAL_DISK_FLAG OpenFlags;
      VIRTUAL_STORAGE_TYPE   ParentVirtualStorageType;
      VIRTUAL_STORAGE_TYPE   SourceVirtualStorageType;
      GUID                   ResiliencyGuid;
    } Version2;
  };
} CREATE_VIRTUAL_DISK_PARAMETERS, *PCREATE_VIRTUAL_DISK_PARAMETERS;