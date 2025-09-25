typedef enum _FsrmReportType {
  FsrmReportType_Unknown = 0,
  FsrmReportType_LargeFiles = 1,
  FsrmReportType_FilesByType = 2,
  FsrmReportType_LeastRecentlyAccessed = 3,
  FsrmReportType_MostRecentlyAccessed = 4,
  FsrmReportType_QuotaUsage = 5,
  FsrmReportType_FilesByOwner = 6,
  FsrmReportType_ExportReport = 7,
  FsrmReportType_DuplicateFiles = 8,
  FsrmReportType_FileScreenAudit = 9,
  FsrmReportType_FilesByProperty = 10,
  FsrmReportType_AutomaticClassification = 11,
  FsrmReportType_Expiration = 12,
  FsrmReportType_FoldersByProperty = 13
} FsrmReportType;