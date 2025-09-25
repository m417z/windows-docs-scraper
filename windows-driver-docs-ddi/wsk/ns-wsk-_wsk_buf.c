typedef struct _WSK_BUF {
  PMDL   Mdl;
  ULONG  Offset;
  SIZE_T Length;
} WSK_BUF, *PWSK_BUF;