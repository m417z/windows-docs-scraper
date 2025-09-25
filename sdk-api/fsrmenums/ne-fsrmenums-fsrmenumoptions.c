typedef enum _FsrmEnumOptions {
  FsrmEnumOptions_None = 0,
  FsrmEnumOptions_Asynchronous = 0x1,
  FsrmEnumOptions_CheckRecycleBin = 0x2,
  FsrmEnumOptions_IncludeClusterNodes = 0x4,
  FsrmEnumOptions_IncludeDeprecatedObjects = 0x8
} FsrmEnumOptions;