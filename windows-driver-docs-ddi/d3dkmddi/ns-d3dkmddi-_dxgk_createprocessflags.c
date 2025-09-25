typedef struct _DXGK_CREATEPROCESSFLAGS {
  union {
    struct {
      UINT SystemProcess : 1;
      UINT GdiProcess : 1;
      UINT VirtualMachineProcess : 1;
      UINT VirtualMachineWorkerProcess : 1;
      UINT SessionIsolatedContainer : 1;
#if ...
      UINT Reserved : 27;
#elif
      UINT Reserved : 28;
#elif
      UINT Reserved : 29;
#else
      UINT Reserved : 30;
#endif
    };
    UINT Value;
  };
} DXGK_CREATEPROCESSFLAGS;