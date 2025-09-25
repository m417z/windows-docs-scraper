typedef struct _D3DKMT_EVICTION_CRITERIA {
  D3DKMT_ALIGN64 UINT64 MinimumSize;
  D3DKMT_ALIGN64 UINT64 MaximumSize;
  struct {
    union {
      struct {
        UINT Primary : 1;
        UINT Reserved : 31;
      } Flags;
      UINT   Value;
    };
  };
} D3DKMT_EVICTION_CRITERIA;