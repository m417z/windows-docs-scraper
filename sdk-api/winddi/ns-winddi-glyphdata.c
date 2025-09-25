typedef struct _GLYPHDATA {
  GLYPHDEF gdf;
  HGLYPH   hg;
  FIX      fxD;
  FIX      fxA;
  FIX      fxAB;
  FIX      fxInkTop;
  FIX      fxInkBottom;
  RECTL    rclInk;
  POINTQF  ptqD;
} GLYPHDATA;