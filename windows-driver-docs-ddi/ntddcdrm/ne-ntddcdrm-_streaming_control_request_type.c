typedef enum _STREAMING_CONTROL_REQUEST_TYPE {
  CdromStreamingDisable,
  CdromStreamingEnableForReadOnly,
  CdromStreamingEnableForWriteOnly,
  CdromStreamingEnableForReadWrite
} STREAMING_CONTROL_REQUEST_TYPE, *PSTREAMING_CONTROL_REQUEST_TYPE;