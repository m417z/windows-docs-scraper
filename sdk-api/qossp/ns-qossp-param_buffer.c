typedef struct _PARAM_BUFFER {
  ULONG ParameterId;
  ULONG Length;
  UCHAR Buffer[1];
} PARAM_BUFFER, *LPPARAM_BUFFER;