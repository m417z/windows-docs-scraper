typedef enum _PROGRESS_INVOKE_SETTING {
  ProgressInvokeNever,
  ProgressInvokeEveryObject,
  ProgressInvokeOnError,
  ProgressCancelOperation,
  ProgressRetryOperation,
  ProgressInvokePrePostError
} PROG_INVOKE_SETTING, *PPROG_INVOKE_SETTING;