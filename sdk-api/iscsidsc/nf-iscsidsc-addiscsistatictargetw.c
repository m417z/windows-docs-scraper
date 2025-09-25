ISDSC_STATUS ISDSC_API AddIScsiStaticTargetW(
  [in]           PWSTR                       TargetName,
  [in, optional] PWSTR                       TargetAlias,
  [in]           ISCSI_TARGET_FLAGS          TargetFlags,
  [in]           BOOLEAN                     Persist,
  [in, optional] PISCSI_TARGET_MAPPINGW      Mappings,
  [in, optional] PISCSI_LOGIN_OPTIONS        LoginOptions,
  [in, optional] PISCSI_TARGET_PORTAL_GROUPW PortalGroup
);