DWORD RtmLockRoute(
  [in]  RTM_ENTITY_HANDLE RtmRegHandle,
  [in]  RTM_ROUTE_HANDLE  RouteHandle,
  [in]  BOOL              Exclusive,
  [in]  BOOL              LockRoute,
  [out] PRTM_ROUTE_INFO   *RoutePointer
);