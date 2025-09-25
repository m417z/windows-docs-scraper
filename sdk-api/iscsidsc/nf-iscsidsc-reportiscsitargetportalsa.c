ISDSC_STATUS ISDSC_API ReportIScsiTargetPortalsA(
  [in, optional] PSTR                  InitiatorName,
  [in]           PSTR                  TargetName,
  [in, optional] PUSHORT               TargetPortalTag,
  [in, out]      PULONG                ElementCount,
  [out]          PISCSI_TARGET_PORTALA Portals
);