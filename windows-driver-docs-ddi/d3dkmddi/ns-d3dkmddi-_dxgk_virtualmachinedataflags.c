typedef struct _DXGK_VIRTUALMACHINEDATAFLAGS {
  union {
    struct {
      UINT SecureVirtualMachine : 1;
      UINT LinuxVirtualMachine : 1;
    };
    UINT Value;
  };
} DXGK_VIRTUALMACHINEDATAFLAGS;