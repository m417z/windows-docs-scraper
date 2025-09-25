DWORD RtmCreateRouteEnum(
  [in]  RTM_ENTITY_HANDLE RtmRegHandle,
  [in]  RTM_DEST_HANDLE   DestHandle,
  [in]  RTM_VIEW_SET      TargetViews,
  [in]  RTM_ENUM_FLAGS    EnumFlags,
  [in]  PRTM_NET_ADDRESS  StartDest,
  [in]  RTM_MATCH_FLAGS   MatchingFlags,
  [in]  PRTM_ROUTE_INFO   CriteriaRoute,
  [in]  ULONG             CriteriaInterface,
  [out] PRTM_ENUM_HANDLE  RtmEnumHandle
);