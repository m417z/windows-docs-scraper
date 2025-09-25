DWORD RtmLockNextHop(
  [in]  RTM_ENTITY_HANDLE  RtmRegHandle,
  [in]  RTM_NEXTHOP_HANDLE NextHopHandle,
  [in]  BOOL               Exclusive,
  [in]  BOOL               LockNextHop,
  [out] PRTM_NEXTHOP_INFO  *NextHopPointer
);