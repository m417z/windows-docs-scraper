typedef struct CLRES_CALLBACK_FUNCTION_TABLE {
  PLOG_EVENT_ROUTINE                                  LogEvent;
  PSET_RESOURCE_STATUS_ROUTINE_EX                     SetResourceStatusEx;
  PSET_RESOURCE_LOCKED_MODE_ROUTINE                   SetResourceLockedMode;
  PSIGNAL_FAILURE_ROUTINE                             SignalFailure;
  PSET_RESOURCE_INMEMORY_NODELOCAL_PROPERTIES_ROUTINE SetResourceInMemoryNodeLocalProperties;
  PEND_CONTROL_CALL                                   EndControlCall;
  PEND_TYPE_CONTROL_CALL                              EndTypeControlCall;
  PEXTEND_RES_CONTROL_CALL                            ExtendControlCall;
  PEXTEND_RES_TYPE_CONTROL_CALL                       ExtendTypeControlCall;
  PRAISE_RES_TYPE_NOTIFICATION                        RaiseResTypeNotification;
  PCHANGE_RESOURCE_PROCESS_FOR_DUMPS                  ChangeResourceProcessForDumps;
  PCHANGE_RES_TYPE_PROCESS_FOR_DUMPS                  ChangeResTypeProcessForDumps;
  PSET_INTERNAL_STATE                                 SetInternalState;
  PSET_RESOURCE_LOCKED_MODE_EX_ROUTINE                SetResourceLockedModeEx;
  PREQUEST_DUMP_ROUTINE                               RequestDump;
  PSET_RESOURCE_WPR_POLICY_ROUTINE                    SetResourceWprPolicy;
  PARM_WPR_WATCHDOG_FOR_CURRENT_RESOURCE_CALL_ROUTINE ArmWprWatchdogForCurrentResourceCall;
} CLRES_CALLBACK_FUNCTION_TABLE, *PCLRES_CALLBACK_FUNCTION_TABLE;