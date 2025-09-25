typedef struct _DXGK_RENDERKM_COMMAND {
  DXGK_RENDERKM_OPERATION OpCode;
  UINT                    CommandSize;
  union {
    DXGK_GDIARG_BITBLT         BitBlt;
    DXGK_GDIARG_COLORFILL      ColorFill;
    DXGK_GDIARG_ALPHABLEND     AlphaBlend;
    DXGK_GDIARG_STRETCHBLT     StretchBlt;
    DXGK_GDIARG_TRANSPARENTBLT TransparentBlt;
    DXGK_GDIARG_CLEARTYPEBLEND ClearTypeBlend;
  } Command;
} DXGK_RENDERKM_COMMAND;