PMGM_RPF_CALLBACK PmgmRpfCallback;

DWORD PmgmRpfCallback(
  [in]      DWORD dwSourceAddr,
  [in]      DWORD dwSourceMask,
  [in]      DWORD dwGroupAddr,
  [in]      DWORD dwGroupMask,
  [in, out] PDWORD pdwInIfIndex,
  [in, out] PDWORD pdwInIfNextHopAddr,
  [in, out] PDWORD pdwUpStreamNbr,
  [in]      DWORD dwHdrSize,
  [in]      PBYTE pbPacketHdr,
  [in, out] PBYTE pbRoute
)
{...}