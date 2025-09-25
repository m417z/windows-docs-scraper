DWORD RtmGetEnumNextHops(
  [in]      RTM_ENTITY_HANDLE   RtmRegHandle,
  [in]      RTM_ENUM_HANDLE     EnumHandle,
  [in, out] PUINT               NumNextHops,
  [out]     PRTM_NEXTHOP_HANDLE NextHopHandles
);