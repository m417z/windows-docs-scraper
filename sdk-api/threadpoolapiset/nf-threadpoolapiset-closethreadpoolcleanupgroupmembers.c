VOID CloseThreadpoolCleanupGroupMembers(
  [in, out]           PTP_CLEANUP_GROUP ptpcg,
  [in]                BOOL              fCancelPendingCallbacks,
  [in, out, optional] PVOID             pvCleanupContext
);