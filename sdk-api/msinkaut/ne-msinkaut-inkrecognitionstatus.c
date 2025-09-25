typedef enum InkRecognitionStatus {
  IRS_NoError = 0,
  IRS_Interrupted = 0x1,
  IRS_ProcessFailed = 0x2,
  IRS_InkAddedFailed = 0x4,
  IRS_SetAutoCompletionModeFailed = 0x8,
  IRS_SetStrokesFailed = 0x10,
  IRS_SetGuideFailed = 0x20,
  IRS_SetFlagsFailed = 0x40,
  IRS_SetFactoidFailed = 0x80,
  IRS_SetPrefixSuffixFailed = 0x100,
  IRS_SetWordListFailed = 0x200
} ;