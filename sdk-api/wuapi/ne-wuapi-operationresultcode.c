typedef enum tagOperationResultCode {
  orcNotStarted = 0,
  orcInProgress = 1,
  orcSucceeded = 2,
  orcSucceededWithErrors = 3,
  orcFailed = 4,
  orcAborted = 5
} OperationResultCode;