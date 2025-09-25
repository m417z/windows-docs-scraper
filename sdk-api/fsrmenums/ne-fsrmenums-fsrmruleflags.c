typedef enum _FsrmRuleFlags {
  FsrmRuleFlags_Disabled = 0x100,
  FsrmRuleFlags_ClearAutomaticallyClassifiedProperty = 0x400,
  FsrmRuleFlags_ClearManuallyClassifiedProperty = 0x800,
  FsrmRuleFlags_Invalid = 0x1000
} FsrmRuleFlags;