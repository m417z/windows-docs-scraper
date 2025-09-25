typedef enum _FsrmStorageModuleCaps {
  FsrmStorageModuleCaps_Unknown = 0,
  FsrmStorageModuleCaps_CanGet = 0x1,
  FsrmStorageModuleCaps_CanSet = 0x2,
  FsrmStorageModuleCaps_CanHandleDirectories = 0x4,
  FsrmStorageModuleCaps_CanHandleFiles = 0x8
} FsrmStorageModuleCaps;