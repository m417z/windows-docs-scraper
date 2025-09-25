typedef struct _D3DDDI_SYNCHRONIZATIONOBJECT_FLAGS {
  union {
    struct {
      UINT Shared : 1;
      UINT NtSecuritySharing : 1;
      UINT CrossAdapter : 1;
      UINT TopOfPipeline : 1;
      UINT NoSignal : 1;
      UINT NoWait : 1;
      UINT NoSignalMaxValueOnTdr : 1;
      UINT NoGPUAccess : 1;
      UINT SignalByKmd : 1;
      UINT Unused : 1;
      UINT UnwaitCpuWaitersOnlyOnDestroy : 1;
#if ...
      UINT Reserved : 20;
#elif
      UINT Reserved : 21;
#elif
      UINT Reserved : 22;
#elif
      UINT Reserved : 23;
#elif
      UINT Reserved : 28;
#else
      UINT Reserved : 29;
#endif
      UINT D3DDDI_SYNCHRONIZATIONOBJECT_FLAGS_RESERVED0 : 1;
    };
    UINT Value;
  };
} D3DDDI_SYNCHRONIZATIONOBJECT_FLAGS;