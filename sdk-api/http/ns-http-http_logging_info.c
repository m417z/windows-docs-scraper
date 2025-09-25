typedef struct _HTTP_LOGGING_INFO {
  HTTP_PROPERTY_FLAGS        Flags;
  ULONG                      LoggingFlags;
  PCWSTR                     SoftwareName;
  USHORT                     SoftwareNameLength;
  USHORT                     DirectoryNameLength;
  PCWSTR                     DirectoryName;
  HTTP_LOGGING_TYPE          Format;
  ULONG                      Fields;
  PVOID                      pExtFields;
  USHORT                     NumOfExtFields;
  USHORT                     MaxRecordSize;
  HTTP_LOGGING_ROLLOVER_TYPE RolloverType;
  ULONG                      RolloverSize;
  PSECURITY_DESCRIPTOR       pSecurityDescriptor;
} HTTP_LOGGING_INFO, *PHTTP_LOGGING_INFO;