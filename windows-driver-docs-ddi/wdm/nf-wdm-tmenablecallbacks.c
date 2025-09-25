NTSTATUS TmEnableCallbacks(
  [in]           PKRESOURCEMANAGER   ResourceManager,
  [in]           PTM_RM_NOTIFICATION CallbackRoutine,
  [in, optional] PVOID               RMKey
);