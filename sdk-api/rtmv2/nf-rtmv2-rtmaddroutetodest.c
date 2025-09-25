DWORD RtmAddRouteToDest(
  [in]      RTM_ENTITY_HANDLE       RtmRegHandle,
  [in, out] PRTM_ROUTE_HANDLE       RouteHandle,
  [in]      PRTM_NET_ADDRESS        DestAddress,
  [in]      PRTM_ROUTE_INFO         RouteInfo,
  [in]      ULONG                   TimeToLive,
  [in]      RTM_ROUTE_LIST_HANDLE   RouteListHandle,
  [in]      RTM_NOTIFY_FLAGS        NotifyType,
  [in]      RTM_NOTIFY_HANDLE       NotifyHandle,
  [in, out] PRTM_ROUTE_CHANGE_FLAGS ChangeFlags
);