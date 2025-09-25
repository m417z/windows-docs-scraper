typedef struct _DXVA_ConfigAlphaCombine {
  DXVA_ConfigQueryOrReplyFunc dwFunction;
  DWORD                       dwReservedBits[3];
  BYTE                        bConfigBlendType;
  BYTE                        bConfigPictureResizing;
  BYTE                        bConfigOnlyUsePicDestRectArea;
  BYTE                        bConfigGraphicResizing;
  BYTE                        bConfigWholePlaneAlpha;
} DXVA_ConfigAlphaCombine, *LPDXVA_ConfigAlphaCombine;