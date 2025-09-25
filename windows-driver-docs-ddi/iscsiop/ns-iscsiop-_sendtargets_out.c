typedef struct _SendTargets_OUT {
  ULONG Status;
  ULONG ResponseSize;
  UCHAR Response[1];
} SendTargets_OUT, *PSendTargets_OUT;