struct DSTORAGE_CONFIGURATION {
  UINT32 NumSubmitThreads;
  INT32 NumBuiltInCpuDecompressionThreads;
  BOOL   ForceMappingLayer;
  BOOL   DisableBypassIO;
  BOOL   DisableTelemetry;
  BOOL   DisableGpuDecompressionMetacommand;
  BOOL   DisableGpuDecompression;
};