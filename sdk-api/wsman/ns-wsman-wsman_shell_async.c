typedef struct _WSMAN_SHELL_ASYNC {
  PVOID                           operationContext;
  WSMAN_SHELL_COMPLETION_FUNCTION completionFunction;
} WSMAN_SHELL_ASYNC;