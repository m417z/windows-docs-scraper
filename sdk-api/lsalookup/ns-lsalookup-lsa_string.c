typedef struct _LSA_STRING {
  USHORT Length;
  USHORT MaximumLength;
  PCHAR  Buffer;
} LSA_STRING, *PLSA_STRING;