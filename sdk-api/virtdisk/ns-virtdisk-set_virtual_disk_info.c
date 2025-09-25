typedef struct _SET_VIRTUAL_DISK_INFO {
  SET_VIRTUAL_DISK_INFO_VERSION Version;
  union {
    PCWSTR ParentFilePath;
    GUID   UniqueIdentifier;
    struct {
      ULONG  ChildDepth;
      PCWSTR ParentFilePath;
    } ParentPathWithDepthInfo;
    ULONG  VhdPhysicalSectorSize;
    GUID   VirtualDiskId;
    BOOL   ChangeTrackingEnabled;
    struct {
      GUID   LinkageId;
      PCWSTR ParentFilePath;
    } ParentLocator;
  };
} SET_VIRTUAL_DISK_INFO, *PSET_VIRTUAL_DISK_INFO;