typedef struct _DFS_SUPPORTED_NAMESPACE_VERSION_INFO {
  ULONG     DomainDfsMajorVersion;
  ULONG     DomainDfsMinorVersion;
  ULONGLONG DomainDfsCapabilities;
  ULONG     StandaloneDfsMajorVersion;
  ULONG     StandaloneDfsMinorVersion;
  ULONGLONG StandaloneDfsCapabilities;
} DFS_SUPPORTED_NAMESPACE_VERSION_INFO, *PDFS_SUPPORTED_NAMESPACE_VERSION_INFO;