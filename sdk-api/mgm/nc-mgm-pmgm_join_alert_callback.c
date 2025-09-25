PMGM_JOIN_ALERT_CALLBACK PmgmJoinAlertCallback;

DWORD PmgmJoinAlertCallback(
  [in] DWORD dwSourceAddr,
  [in] DWORD dwSourceMask,
  [in] DWORD dwGroupAddr,
  [in] DWORD dwGroupMask,
  [in] BOOL bMemberUpdate
)
{...}