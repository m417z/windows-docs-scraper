ISDSC_STATUS ISDSC_API AddIScsiConnectionA(
  [in]            PISCSI_UNIQUE_SESSION_ID    UniqueSessionId,
  [in]            PVOID                       Reserved,
  [in, optional]  ULONG                       InitiatorPortNumber,
  [in]            PISCSI_TARGET_PORTALA       TargetPortal,
  [in, optional]  ISCSI_SECURITY_FLAGS        SecurityFlags,
  [in, optional]  PISCSI_LOGIN_OPTIONS        LoginOptions,
  [in, optional]  ULONG                       KeySize,
  [in, optional]  PCHAR                       Key,
  [out, optional] PISCSI_UNIQUE_CONNECTION_ID ConnectionId
);