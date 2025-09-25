DOT11EXTIHV_PERFORM_POST_ASSOCIATE Dot11extihvPerformPostAssociate;

DWORD Dot11extihvPerformPostAssociate(
  [in, optional] HANDLE hIhvExtAdapter,
  [in, optional] HANDLE hSecuritySessionID,
  [in]           PDOT11_PORT_STATE pPortState,
  [in]           ULONG uDot11AssocParamsBytes,
  [in]           PDOT11_ASSOCIATION_COMPLETION_PARAMETERS pDot11AssocParams
)
{...}