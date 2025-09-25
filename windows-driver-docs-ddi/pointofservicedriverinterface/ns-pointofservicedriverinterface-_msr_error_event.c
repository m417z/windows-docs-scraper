typedef struct _MSR_ERROR_EVENT {
  PosEventDataHeader            Header;
  MsrTrackErrorType             Track1Status;
  MsrTrackErrorType             Track2Status;
  MsrTrackErrorType             Track3Status;
  MsrTrackErrorType             Track4Status;
  DriverUnifiedPosErrorSeverity Severity;
  DriverUnifiedPosErrorReason   Reason;
  UINT32                        ExtendedReason;
  MSR_DATA_RECEIVED             CardData;
  wchar_t                       Message[MSR_ERROR_MAX_MESSAGE_LENGTH];
} MSR_ERROR_EVENT, *PMSR_ERROR_EVENT;