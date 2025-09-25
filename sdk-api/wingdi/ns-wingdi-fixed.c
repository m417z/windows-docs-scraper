typedef struct _FIXED {
#if ...
  WORD  fract;
#if ...
  short value;
#else
  short value;
#endif
#else
  WORD  fract;
#endif
} FIXED;