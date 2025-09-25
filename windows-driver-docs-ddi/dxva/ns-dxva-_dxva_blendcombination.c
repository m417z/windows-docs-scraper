typedef struct _DXVA_BlendCombination {
  WORD             wPictureSourceIndex;
  WORD             wBlendedDestinationIndex;
  RECT             PictureSourceRect16thPel;
  RECT             PictureDestinationRect;
  RECT             GraphicSourceRect;
  RECT             GraphicDestinationRect;
  WORD             wBlendDelay;
  BYTE             bBlendOn;
  BYTE             bWholePlaneAlpha;
  DXVA_AYUVsample2 OutsideYUVcolor;
} DXVA_BlendCombination, *LPDXVA_BlendCombination;