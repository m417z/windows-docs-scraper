typedef struct _DXGK_PRE_START_INFO {
  union {
    struct {
      UINT ReservedIn;
    };
    UINT Input;
  };
  union {
    struct {
      UINT SupportPreserveBootDisplay : 1;
      UINT IsUEFIFrameBufferCpuAccessibleDuringStartup : 1;
      UINT ReservedOut : 30;
    };
    UINT Output;
  };
} DXGK_PRE_START_INFO, *PDXGK_PRE_START_INFO;