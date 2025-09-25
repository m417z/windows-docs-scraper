ISDSC_STATUS ISDSC_API AddIScsiSendTargetPortalA(
  [in, optional] PSTR                  InitiatorInstance,
  [in, optional] ULONG                 InitiatorPortNumber,
  [in, optional] PISCSI_LOGIN_OPTIONS  LoginOptions,
  [in, optional] ISCSI_SECURITY_FLAGS  SecurityFlags,
                 PISCSI_TARGET_PORTALA Portal
);