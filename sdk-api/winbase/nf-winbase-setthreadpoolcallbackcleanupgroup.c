VOID SetThreadpoolCallbackCleanupGroup(
  [in, out]      PTP_CALLBACK_ENVIRON              pcbe,
  [in]           PTP_CLEANUP_GROUP                 ptpcg,
  [in, optional] PTP_CLEANUP_GROUP_CANCEL_CALLBACK pfng
);