PMGM_PRUNE_ALERT_CALLBACK PmgmPruneAlertCallback;

DWORD PmgmPruneAlertCallback(
  [in]      DWORD dwSourceAddr,
  [in]      DWORD dwSourceMask,
  [in]      DWORD dwGroupAddr,
  [in]      DWORD dwGroupMask,
  [in]      DWORD dwIfIndex,
  [in]      DWORD dwIfNextHopAddr,
  [in]      BOOL bMemberDelete,
  [in, out] PDWORD pdwTimeout
)
{...}