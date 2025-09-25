PMGM_LOCAL_JOIN_CALLBACK PmgmLocalJoinCallback;

DWORD PmgmLocalJoinCallback(
  [in] DWORD dwSourceAddr,
  [in] DWORD dwSourceMask,
  [in] DWORD dwGroupAddr,
  [in] DWORD dwGroupMask,
  [in] DWORD dwIfIndex,
  [in] DWORD dwIfNextHopAddr
)
{...}