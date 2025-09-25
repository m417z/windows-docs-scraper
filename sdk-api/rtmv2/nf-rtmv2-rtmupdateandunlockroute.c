DWORD RtmUpdateAndUnlockRoute(
  [in]  RTM_ENTITY_HANDLE       RtmRegHandle,
  [in]  RTM_ROUTE_HANDLE        RouteHandle,
  [in]  ULONG                   TimeToLive,
  [in]  RTM_ROUTE_LIST_HANDLE   RouteListHandle,
  [in]  RTM_NOTIFY_FLAGS        NotifyType,
  [in]  RTM_NOTIFY_HANDLE       NotifyHandle,
  [out] PRTM_ROUTE_CHANGE_FLAGS ChangeFlags
);