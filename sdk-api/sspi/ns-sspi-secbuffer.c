typedef struct _SecBuffer {
  unsigned long cbBuffer;
  unsigned long BufferType;
#if ...
  char          *pvBuffer;
#else
  void SEC_FAR  *pvBuffer;
#endif
} SecBuffer, *PSecBuffer;