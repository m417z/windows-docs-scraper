DWORD RtmGetRegisteredEntities(
  [in]      RTM_ENTITY_HANDLE  RtmRegHandle,
  [in, out] PUINT              NumEntities,
  [out]     PRTM_ENTITY_HANDLE EntityHandles,
  [out]     PRTM_ENTITY_INFO   EntityInfos
);