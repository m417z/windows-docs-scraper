typedef enum _ETW_PROCESS_HANDLE_INFO_TYPE {
  EtwQueryPartitionInformation = 1,
  EtwQueryPartitionInformationV2 = 2,
  EtwQueryLastDroppedTimes = 3,
  EtwQueryLogFileHeader,
  EtwQueryProcessHandleInfoMax
} ETW_PROCESS_HANDLE_INFO_TYPE;