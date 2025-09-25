DWORD RtmGetEnumDests(
  [in]      RTM_ENTITY_HANDLE RtmRegHandle,
  [in]      RTM_ENUM_HANDLE   EnumHandle,
  [in, out] PUINT             NumDests,
  [out]     PRTM_DEST_INFO    DestInfos
);