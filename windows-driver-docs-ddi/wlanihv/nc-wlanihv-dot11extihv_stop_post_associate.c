DOT11EXTIHV_STOP_POST_ASSOCIATE Dot11extihvStopPostAssociate;

DWORD Dot11extihvStopPostAssociate(
  [in, optional] HANDLE hIhvExtAdapter,
  [in]           PDOT11_MAC_ADDRESS pPeer,
  [in]           DOT11_ASSOC_STATUS dot11AssocStatus
)
{...}