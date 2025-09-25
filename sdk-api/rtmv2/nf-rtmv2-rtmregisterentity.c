DWORD RtmRegisterEntity(
  [in]  PRTM_ENTITY_INFO           RtmEntityInfo,
  [in]  PRTM_ENTITY_EXPORT_METHODS ExportMethods,
  [in]  RTM_EVENT_CALLBACK         EventCallback,
  [in]  BOOL                       ReserveOpaquePointer,
  [out] PRTM_REGN_PROFILE          RtmRegProfile,
  [out] PRTM_ENTITY_HANDLE         RtmRegHandle
);