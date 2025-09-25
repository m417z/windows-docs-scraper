typedef struct _DXGK_GPUPCAPS {
  union {
    struct {
      UINT VirtualMachineHibernation : 1;
      UINT HotDriverUpdate : 1;
      UINT LiveMigration : 1;
      UINT ScatterMapReserve : 1;
#if ...
      UINT Reserved : 28;
#else
      UINT Reserved : 30;
#endif
    };
    UINT Value;
  } Caps;
} DXGK_GPUPCAPS;