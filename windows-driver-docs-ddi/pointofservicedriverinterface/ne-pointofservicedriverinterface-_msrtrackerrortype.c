typedef enum _MsrTrackErrorType {
  MsrTrackErrorType_Unknown,
  MsrTrackErrorType_None,
  MsrTrackErrorType_StartSentinelError,
  MsrTrackErrorType_EndSentinelError,
  MsrTrackErrorType_ParityError,
  MsrTrackErrorType_LrcError
} MsrTrackErrorType;