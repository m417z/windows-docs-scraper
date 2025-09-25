typedef struct _ACX_DATAFORMAT_CONFIG {
  ULONG               Size;
  ULONG               Flags;
  ACX_DATAFORMAT_TYPE Type;
  union {
    PVOID KsFormat;
  } u;
} ACX_DATAFORMAT_CONFIG, *PACX_DATAFORMAT_CONFIG;