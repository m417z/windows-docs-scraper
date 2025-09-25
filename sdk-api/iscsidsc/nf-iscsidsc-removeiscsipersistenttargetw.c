ISDSC_STATUS ISDSC_API RemoveIScsiPersistentTargetW(
  [in]           PWSTR                 InitiatorInstance,
  [in, optional] ULONG                 InitiatorPortNumber,
  [in]           PWSTR                 TargetName,
  [in]           PISCSI_TARGET_PORTALW Portal
);