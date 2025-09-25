typedef struct _DXGKARGCB_SIGNALEVENT {
  HANDLE hDxgkProcess;
  HANDLE hEvent;
  union {
    struct {
      UINT CpuEventObject : 1;
#if ...
      UINT Reserved : 31;
#else
      UINT Reserved : 32;
#endif
    };
    UINT Flags;
  };
} DXGKARGCB_SIGNALEVENT;