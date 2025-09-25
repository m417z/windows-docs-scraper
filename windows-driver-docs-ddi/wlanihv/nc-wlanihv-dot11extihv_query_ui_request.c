DOT11EXTIHV_QUERY_UI_REQUEST Dot11extihvQueryUiRequest;

DWORD Dot11extihvQueryUiRequest(
  [in, optional] HANDLE hIhvExtAdapter,
  [in]           DOT11EXT_IHV_CONNECTION_PHASE connectionPhase,
  [out]          PDOT11EXT_IHV_UI_REQUEST *ppIhvUIRequest
)
{...}