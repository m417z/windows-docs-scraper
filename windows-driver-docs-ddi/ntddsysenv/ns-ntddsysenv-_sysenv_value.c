typedef struct _SYSENV_VALUE {
  ULONG Attributes;
  ULONG ValueLength;
  UCHAR ValueData[ANYSIZE_ARRAY];
} SYSENV_VALUE, *PSYSENV_VALUE;