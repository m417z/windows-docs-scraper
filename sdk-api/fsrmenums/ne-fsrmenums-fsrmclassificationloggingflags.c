typedef enum _FsrmClassificationLoggingFlags {
  FsrmClassificationLoggingFlags_None = 0,
  FsrmClassificationLoggingFlags_ClassificationsInLogFile = 0x1,
  FsrmClassificationLoggingFlags_ErrorsInLogFile = 0x2,
  FsrmClassificationLoggingFlags_ClassificationsInSystemLog = 0x4,
  FsrmClassificationLoggingFlags_ErrorsInSystemLog = 0x8
} FsrmClassificationLoggingFlags;