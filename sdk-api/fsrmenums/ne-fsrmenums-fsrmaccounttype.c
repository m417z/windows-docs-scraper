typedef enum _FsrmAccountType {
  FsrmAccountType_Unknown = 0,
  FsrmAccountType_NetworkService = 1,
  FsrmAccountType_LocalService = 2,
  FsrmAccountType_LocalSystem = 3,
  FsrmAccountType_InProc = 4,
  FsrmAccountType_External = 5,
  FsrmAccountType_Automatic = 500
} FsrmAccountType;