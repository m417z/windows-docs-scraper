DWORD RtmCreateDestEnum(
  [in]  RTM_ENTITY_HANDLE RtmRegHandle,
  [in]  RTM_VIEW_SET      TargetViews,
  [in]  RTM_ENUM_FLAGS    EnumFlags,
  [in]  PRTM_NET_ADDRESS  NetAddress,
  [in]  ULONG             ProtocolId,
  [out] PRTM_ENUM_HANDLE  RtmEnumHandle
);