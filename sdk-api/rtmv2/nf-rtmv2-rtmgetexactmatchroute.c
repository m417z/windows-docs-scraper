DWORD RtmGetExactMatchRoute(
  [in]      RTM_ENTITY_HANDLE RtmRegHandle,
  [in]      PRTM_NET_ADDRESS  DestAddress,
  [in]      RTM_MATCH_FLAGS   MatchingFlags,
  [in, out] PRTM_ROUTE_INFO   RouteInfo,
  [in]      ULONG             InterfaceIndex,
  [in]      RTM_VIEW_SET      TargetViews,
  [out]     PRTM_ROUTE_HANDLE RouteHandle
);