PMGM_CREATION_ALERT_CALLBACK PmgmCreationAlertCallback;

DWORD PmgmCreationAlertCallback(
  [in]      DWORD dwSourceAddr,
  [in]      DWORD dwSourceMask,
  [in]      DWORD dwGroupAddr,
  [in]      DWORD dwGroupMask,
  [in]      DWORD dwInIfIndex,
  [in]      DWORD dwInIfNextHopAddr,
  [in]      DWORD dwIfCount,
  [in, out] PMGM_IF_ENTRY pmieOutIfList
)
{...}