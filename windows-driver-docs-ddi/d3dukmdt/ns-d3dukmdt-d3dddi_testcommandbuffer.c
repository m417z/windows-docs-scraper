typedef struct _D3DDDI_TESTCOMMANDBUFFER {
  union {
    D3DDDI_TESTCOMMANDBUFFER_COPY Copy;
    D3DDDI_TESTCOMMANDBUFFER_FILL Fill;
    char                          Reserved[64];
  };
  D3DDDI_TESTCOMMANDBUFFEROP Operation;
  UINT                       Reserved1;
} D3DDDI_TESTCOMMANDBUFFER;