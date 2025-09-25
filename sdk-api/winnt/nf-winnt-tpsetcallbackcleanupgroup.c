VOID TpSetCallbackCleanupGroup(
  [in, out]      PTP_CALLBACK_ENVIRON              CallbackEnviron,
  [in]           PTP_CLEANUP_GROUP                 CleanupGroup,
  [in, optional] PTP_CLEANUP_GROUP_CANCEL_CALLBACK CleanupGroupCancelCallback
);