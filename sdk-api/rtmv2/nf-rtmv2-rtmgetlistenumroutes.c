DWORD RtmGetListEnumRoutes(
  [in]      RTM_ENTITY_HANDLE RtmRegHandle,
  [in]      RTM_ENUM_HANDLE   EnumHandle,
  [in, out] PUINT             NumRoutes,
  [out]     PRTM_ROUTE_HANDLE RouteHandles
);