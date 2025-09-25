CLFSUSER_API NTSTATUS ClfsMgmtSetLogFileSize(
  [in]           PLOG_FILE_OBJECT                     LogFile,
  [in]           PULONGLONG                           NewSizeInContainers,
  [out]          PULONGLONG                           ResultingSizeInContainers,
  [in, optional] PCLFS_SET_LOG_SIZE_COMPLETE_CALLBACK CompletionRoutine,
  [in, optional] PVOID                                CompletionRoutineData
);