ISDSC_STATUS ISDSC_API AddIScsiStaticTargetA(
  [in]           PSTR                        TargetName,
  [in, optional] PSTR                        TargetAlias,
  [in]           ISCSI_TARGET_FLAGS          TargetFlags,
  [in]           BOOLEAN                     Persist,
  [in, optional] PISCSI_TARGET_MAPPINGA      Mappings,
  [in, optional] PISCSI_LOGIN_OPTIONS        LoginOptions,
  [in, optional] PISCSI_TARGET_PORTAL_GROUPA PortalGroup
);