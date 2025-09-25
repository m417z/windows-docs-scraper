typedef struct _CLIPLINE {
  POINTFIX ptfxA;
  POINTFIX ptfxB;
  LONG     lStyleState;
  ULONG    c;
  RUN      arun[1];
} CLIPLINE, *PCLIPLINE;