typedef struct _MF_SINK_WRITER_STATISTICS {
  DWORD    cb;
  LONGLONG llLastTimestampReceived;
  LONGLONG llLastTimestampEncoded;
  LONGLONG llLastTimestampProcessed;
  LONGLONG llLastStreamTickReceived;
  LONGLONG llLastSinkSampleRequest;
  QWORD    qwNumSamplesReceived;
  QWORD    qwNumSamplesEncoded;
  QWORD    qwNumSamplesProcessed;
  QWORD    qwNumStreamTicksReceived;
  DWORD    dwByteCountQueued;
  QWORD    qwByteCountProcessed;
  DWORD    dwNumOutstandingSinkSampleRequests;
  DWORD    dwAverageSampleRateReceived;
  DWORD    dwAverageSampleRateEncoded;
  DWORD    dwAverageSampleRateProcessed;
} MF_SINK_WRITER_STATISTICS;