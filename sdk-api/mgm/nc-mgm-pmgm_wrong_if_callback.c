PMGM_WRONG_IF_CALLBACK PmgmWrongIfCallback;

DWORD PmgmWrongIfCallback(
  [in] DWORD dwSourceAddr,
  [in] DWORD dwGroupAddr,
  [in] DWORD dwIfIndex,
  [in] DWORD dwIfNextHopAddr,
  [in] DWORD dwHdrSize,
  [in] PBYTE pbPacketHdr
)
{...}