typedef struct _D3DDDI_TESTCOMMANDBUFFER_FILL {
  D3DKMT_ALIGN64 D3DGPU_VIRTUAL_ADDRESS DstAddress;
  UINT                                  NumBytes;
  UINT                                  Pattern;
} D3DDDI_TESTCOMMANDBUFFER_FILL;