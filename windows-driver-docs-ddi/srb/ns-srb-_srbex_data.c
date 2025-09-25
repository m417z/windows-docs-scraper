typedef struct _SRBEX_DATA {
  SRBEXDATATYPE Type;
  ULONG         Length;
  UCHAR         Data[ANYSIZE_ARRAY];
} SRBEX_DATA, *PSRBEX_DATA;