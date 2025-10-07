struct DSTORAGE_CONFIGURATION1 {
  UINT32 NumSubmitThreads;
  INT32 NumBuiltInCpuDecompressionThreads;
  BOOL   ForceMappingLayer;
  BOOL   DisableBypassIO;
  BOOL   DisableTelemetry;
  BOOL   DisableGpuDecompressionMetacommand;
  BOOL   DisableGpuDecompression;
  BOOL   ForceFileBuffering;
};