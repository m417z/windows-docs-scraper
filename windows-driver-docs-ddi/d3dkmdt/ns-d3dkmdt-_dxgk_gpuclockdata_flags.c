typedef struct _DXGK_GPUCLOCKDATA_FLAGS {
  union {
    struct {
      UINT ContextManagementProcessor : 1;
      UINT Reserved : 31;
    };
    UINT32 Value;
  };
} DXGK_GPUCLOCKDATA_FLAGS;