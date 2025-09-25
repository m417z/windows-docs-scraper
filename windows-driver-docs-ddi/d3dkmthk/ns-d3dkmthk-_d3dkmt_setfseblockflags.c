typedef union _D3DKMT_SETFSEBLOCKFLAGS {
  struct {
    UINT Block : 1;
    UINT Reserved : 31;
  };
  UINT   Value;
} D3DKMT_SETFSEBLOCKFLAGS;