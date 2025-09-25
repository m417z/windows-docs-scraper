typedef struct _WHEA_PSHED_PLUGIN_CALLBACKS {
  PSHED_PI_GET_ALL_ERROR_SOURCES      GetAllErrorSources;
  PVOID                               Reserved;
  PSHED_PI_GET_ERROR_SOURCE_INFO      GetErrorSourceInfo;
  PSHED_PI_SET_ERROR_SOURCE_INFO      SetErrorSourceInfo;
  PSHED_PI_ENABLE_ERROR_SOURCE        EnableErrorSource;
  PSHED_PI_DISABLE_ERROR_SOURCE       DisableErrorSource;
  PSHED_PI_WRITE_ERROR_RECORD         WriteErrorRecord;
  PSHED_PI_READ_ERROR_RECORD          ReadErrorRecord;
  PSHED_PI_CLEAR_ERROR_RECORD         ClearErrorRecord;
  PSHED_PI_RETRIEVE_ERROR_INFO        RetrieveErrorInfo;
  PSHED_PI_FINALIZE_ERROR_RECORD      FinalizeErrorRecord;
  PSHED_PI_CLEAR_ERROR_STATUS         ClearErrorStatus;
  PSHED_PI_ATTEMPT_ERROR_RECOVERY     AttemptRecovery;
  PSHED_PI_GET_INJECTION_CAPABILITIES GetInjectionCapabilities;
  PSHED_PI_INJECT_ERROR               InjectError;
} WHEA_PSHED_PLUGIN_CALLBACKS, *PWHEA_PSHED_PLUGIN_CALLBACKS;