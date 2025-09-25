ISDSC_STATUS ISDSC_API ReportIScsiTargetPortalsW(
  [in, optional] PWSTR                 InitiatorName,
  [in]           PWSTR                 TargetName,
  [in, optional] PUSHORT               TargetPortalTag,
  [in, out]      PULONG                ElementCount,
  [out]          PISCSI_TARGET_PORTALW Portals
);