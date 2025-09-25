typedef struct _SecBufferDesc {
  unsigned long ulVersion;
  unsigned long cBuffers;
  PSecBuffer    pBuffers;
} SecBufferDesc, *PSecBufferDesc;