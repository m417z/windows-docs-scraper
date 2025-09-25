typedef struct _GET_VIRTUAL_DISK_INFO {
  GET_VIRTUAL_DISK_INFO_VERSION Version;
  union {
    struct {
      ULONGLONG VirtualSize;
      ULONGLONG PhysicalSize;
      ULONG     BlockSize;
      ULONG     SectorSize;
    } Size;
    GUID                 Identifier;
    struct {
      BOOL  ParentResolved;
      WCHAR ParentLocationBuffer[1];
    } ParentLocation;
    GUID                 ParentIdentifier;
    ULONG                ParentTimestamp;
    VIRTUAL_STORAGE_TYPE VirtualStorageType;
    ULONG                ProviderSubtype;
    BOOL                 Is4kAligned;
    BOOL                 IsLoaded;
    struct {
      ULONG LogicalSectorSize;
      ULONG PhysicalSectorSize;
      BOOL  IsRemote;
    } PhysicalDisk;
    ULONG                VhdPhysicalSectorSize;
    ULONGLONG            SmallestSafeVirtualSize;
    ULONG                FragmentationPercentage;
    GUID                 VirtualDiskId;
    struct {
      BOOL  Enabled;
      BOOL  NewerChanges;
      WCHAR MostRecentId[1];
    } ChangeTrackingState;
  };
} GET_VIRTUAL_DISK_INFO, *PGET_VIRTUAL_DISK_INFO;