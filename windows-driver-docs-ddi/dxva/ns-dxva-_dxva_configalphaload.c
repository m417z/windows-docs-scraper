typedef struct _DXVA_ConfigAlphaLoad {
  DXVA_ConfigQueryOrReplyFunc dwFunction;
  DWORD                       dwReservedBits[3];
  BYTE                        bConfigDataType;
} DXVA_ConfigAlphaLoad, *LPDXVA_ConfigAlphaLoad;