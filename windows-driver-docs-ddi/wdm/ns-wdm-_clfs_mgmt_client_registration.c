typedef struct _CLFS_MGMT_CLIENT_REGISTRATION {
  ULONG                                      Version;
  PCLFS_CLIENT_ADVANCE_TAIL_CALLBACK         AdvanceTailCallback;
  PVOID                                      AdvanceTailCallbackData;
  PCLFS_CLIENT_LFF_HANDLER_COMPLETE_CALLBACK LogGrowthCompleteCallback;
  PVOID                                      LogGrowthCompleteCallbackData;
  PCLFS_CLIENT_LOG_UNPINNED_CALLBACK         LogUnpinnedCallback;
  PVOID                                      LogUnpinnedCallbackData;
} CLFS_MGMT_CLIENT_REGISTRATION, *PCLFS_MGMT_CLIENT_REGISTRATION;