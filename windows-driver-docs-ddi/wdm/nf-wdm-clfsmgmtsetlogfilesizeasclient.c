CLFSUSER_API NTSTATUS ClfsMgmtSetLogFileSizeAsClient(
  [in]            PLOG_FILE_OBJECT                     LogFile,
  [in, optional]  CLFS_MGMT_CLIENT                     ClientCookie,
  [in]            PULONGLONG                           NewSizeInContainers,
  [out, optional] PULONGLONG                           ResultingSizeInContainers,
  [in, optional]  PCLFS_SET_LOG_SIZE_COMPLETE_CALLBACK CompletionRoutine,
  [in, optional]  PVOID                                CompletionRoutineData
);