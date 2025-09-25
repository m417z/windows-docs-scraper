typedef struct _DXGK_QUERYADAPTERINFOFLAGS {
  union {
    struct {
      UINT VirtualMachineData : 1;
      UINT SecureVirtualMachine : 1;
      UINT Reserved : 30;
    };
    UINT Value;
  };
} DXGK_QUERYADAPTERINFOFLAGS;