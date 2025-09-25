PMGM_LOCAL_LEAVE_CALLBACK PmgmLocalLeaveCallback;

DWORD PmgmLocalLeaveCallback(
  [in] DWORD dwSourceAddr,
  [in] DWORD dwSourceMask,
  [in] DWORD dwGroupAddr,
  [in] DWORD dwGroupMask,
  [in] DWORD dwIfIndex,
  [in] DWORD dwIfNextHopAddr
)
{...}