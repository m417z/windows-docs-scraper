typedef struct {
  LONG timeCount;
  LONG timeDraw;
  LONG timeDecompress;
  LONG timeDither;
  LONG timeStretch;
  LONG timeBlt;
  LONG timeSetDIBits;
} DRAWDIBTIME, *LPDRAWDIBTIME;