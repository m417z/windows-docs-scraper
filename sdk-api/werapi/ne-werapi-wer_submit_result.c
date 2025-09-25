typedef enum _WER_SUBMIT_RESULT {
  WerReportQueued,
  WerReportUploaded,
  WerReportDebug,
  WerReportFailed,
  WerDisabled,
  WerReportCancelled,
  WerDisabledQueue,
  WerReportAsync,
  WerCustomAction,
  WerThrottled,
  WerReportUploadedCab,
  WerStorageLocationNotFound,
  WerSubmitResultMax
} WER_SUBMIT_RESULT, *PWER_SUBMIT_RESULT;