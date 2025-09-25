ISDSC_STATUS ISDSC_API LoginIScsiTargetA(
  [in]           PSTR                        TargetName,
  [in]           BOOLEAN                     IsInformationalSession,
  [in, optional] PSTR                        InitiatorInstance,
  [in, optional] ULONG                       InitiatorPortNumber,
  [in, optional] PISCSI_TARGET_PORTALA       TargetPortal,
  [in, optional] ISCSI_SECURITY_FLAGS        SecurityFlags,
  [in, optional] PISCSI_TARGET_MAPPINGA      Mappings,
  [in, optional] PISCSI_LOGIN_OPTIONS        LoginOptions,
  [in, optional] ULONG                       KeySize,
  [in, optional] PCHAR                       Key,
  [in]           BOOLEAN                     IsPersistent,
  [out]          PISCSI_UNIQUE_SESSION_ID    UniqueSessionId,
  [out]          PISCSI_UNIQUE_CONNECTION_ID UniqueConnectionId
);