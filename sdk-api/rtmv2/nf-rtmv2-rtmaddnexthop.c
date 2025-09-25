DWORD RtmAddNextHop(
  [in]      RTM_ENTITY_HANDLE         RtmRegHandle,
  [in]      PRTM_NEXTHOP_INFO         NextHopInfo,
  [in, out] PRTM_NEXTHOP_HANDLE       NextHopHandle,
  [out]     PRTM_NEXTHOP_CHANGE_FLAGS ChangeFlags
);