typedef struct _WSMAN_SHELL_STARTUP_INFO_V10 {
  WSMAN_STREAM_ID_SET            *inputStreamSet;
  WSMAN_STREAM_ID_SET            *outputStreamSet;
  DWORD                          idleTimeoutMs;
  PCWSTR                         workingDirectory;
  WSMAN_ENVIRONMENT_VARIABLE_SET *variableSet;
} WSMAN_SHELL_STARTUP_INFO_V10;