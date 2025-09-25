DWORD RtmRegisterForChangeNotification(
  [in]  RTM_ENTITY_HANDLE  RtmRegHandle,
  [in]  RTM_VIEW_SET       TargetViews,
  [in]  RTM_NOTIFY_FLAGS   NotifyFlags,
  [in]  PVOID              NotifyContext,
  [out] PRTM_NOTIFY_HANDLE NotifyHandle
);