DOT11EXT_POST_ASSOCIATE_COMPLETION Dot11extPostAssociateCompletion;

DWORD Dot11extPostAssociateCompletion(
  [in, optional] HANDLE hDot11SvcHandle,
  [in, optional] HANDLE hSecuritySessionID,
  [in, optional] PDOT11_MAC_ADDRESS pPeer,
  [in]           DWORD dwReasonCode,
  [in]           DWORD dwWin32Error
)
{...}