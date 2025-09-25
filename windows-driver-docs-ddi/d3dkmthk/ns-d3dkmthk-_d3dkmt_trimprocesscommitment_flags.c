typedef union _D3DKMT_TRIMPROCESSCOMMITMENT_FLAGS {
  struct {
    UINT Lazy : 1;
    UINT OnlyRepurposed : 1;
    UINT Reserved : 30;
  };
  UINT   Value;
} D3DKMT_TRIMPROCESSCOMMITMENT_FLAGS;