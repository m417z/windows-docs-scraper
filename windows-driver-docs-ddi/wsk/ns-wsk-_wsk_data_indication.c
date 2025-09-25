typedef struct _WSK_DATA_INDICATION {
  struct _WSK_DATA_INDICATION *Next;
  WSK_BUF                     Buffer;
} WSK_DATA_INDICATION, *PWSK_DATA_INDICATION;