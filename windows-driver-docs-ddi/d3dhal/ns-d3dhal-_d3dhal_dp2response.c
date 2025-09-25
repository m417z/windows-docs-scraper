typedef struct _D3DHAL_DP2RESPONSE {
  BYTE  bCommand;
  BYTE  bReserved;
  WORD  wStateCount;
  DWORD dwTotalSize;
} D3DHAL_DP2RESPONSE, *LPD3DHAL_DP2RESPONSE;