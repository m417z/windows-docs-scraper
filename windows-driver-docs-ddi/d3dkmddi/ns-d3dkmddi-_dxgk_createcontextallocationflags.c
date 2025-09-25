typedef struct _DXGK_CREATECONTEXTALLOCATIONFLAGS {
  union {
    struct {
      UINT SharedAcrossContexts : 1;
      UINT MapGpuVirtualAddress : 1;
#if ...
      UINT Reserved : 30;
#else
      UINT Reserved : 31;
#endif
    };
    [in] UINT Value;
  };
} DXGK_CREATECONTEXTALLOCATIONFLAGS;