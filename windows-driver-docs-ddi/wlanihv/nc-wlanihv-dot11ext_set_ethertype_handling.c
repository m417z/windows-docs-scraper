DOT11EXT_SET_ETHERTYPE_HANDLING Dot11extSetEthertypeHandling;

DWORD Dot11extSetEthertypeHandling(
  [in, optional] HANDLE hDot11SvcHandle,
  [in]           ULONG uMaxBackLog,
  [in]           ULONG uNumOfExemption,
  [in, optional] PDOT11_PRIVACY_EXEMPTION pExemption,
  [in]           ULONG uNumOfRegistration,
  [in, optional] USHORT *pusRegistration
)
{...}