typedef union _D3DKMT_QUERYFSEFLAGS {
  struct {
    UINT Blocked : 1;
    UINT Reserved : 31;
  };
  UINT   Value;
} D3DKMT_QUERYFSEBLOCKFLAGS;