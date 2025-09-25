DWORD RtmGetMostSpecificDestination(
  [in]  RTM_ENTITY_HANDLE RtmRegHandle,
  [in]  PRTM_NET_ADDRESS  DestAddress,
  [in]  ULONG             ProtocolId,
  [in]  RTM_VIEW_SET      TargetViews,
  [out] PRTM_DEST_INFO    DestInfo
);