DWORD RtmGetLessSpecificDestination(
  [in]  RTM_ENTITY_HANDLE RtmRegHandle,
  [in]  RTM_DEST_HANDLE   DestHandle,
  [in]  ULONG             ProtocolId,
  [in]  RTM_VIEW_SET      TargetViews,
  [out] PRTM_DEST_INFO    DestInfo
);