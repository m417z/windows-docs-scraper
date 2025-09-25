typedef struct _DXGK_DEVICEINFOFLAGS {
  union {
    struct {
      UINT GuaranteedDmaBufferContract : 1;
      UINT Reserved : 31;
    };
    [out] UINT Value;
  };
} DXGK_DEVICEINFOFLAGS;