typedef enum _FsrmQuotaFlags {
  FsrmQuotaFlags_Enforce = 0x100,
  FsrmQuotaFlags_Disable = 0x200,
  FsrmQuotaFlags_StatusIncomplete = 0x10000,
  FsrmQuotaFlags_StatusRebuilding = 0x20000
} FsrmQuotaFlags;