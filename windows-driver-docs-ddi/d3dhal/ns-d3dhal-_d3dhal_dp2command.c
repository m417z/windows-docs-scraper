typedef struct _D3DHAL_DP2COMMAND {
  BYTE  bCommand;
  BYTE  bReserved;
  union {
    WORD wPrimitiveCount;
    WORD wStateCount;
  };
} D3DHAL_DP2COMMAND, *LPD3DHAL_DP2COMMAND;