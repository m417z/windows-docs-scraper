typedef struct PRJ_PLACEHOLDER_INFO {
  PRJ_FILE_BASIC_INFO          FileBasicInfo;
  struct {
    UINT32 EaBufferSize;
    UINT32 OffsetToFirstEa;
  } EaInformation;
  struct {
    UINT32 SecurityBufferSize;
    UINT32 OffsetToSecurityDescriptor;
  } SecurityInformation;
  struct {
    UINT32 StreamsInfoBufferSize;
    UINT32 OffsetToFirstStreamInfo;
  } StreamsInformation;
  PRJ_PLACEHOLDER_VERSION_INFO VersionInfo;
  UINT8                        VariableData[1];
} PRJ_PLACEHOLDER_INFO;