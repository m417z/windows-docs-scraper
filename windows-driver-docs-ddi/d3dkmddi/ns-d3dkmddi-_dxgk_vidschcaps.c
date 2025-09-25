typedef struct _DXGK_VIDSCHCAPS {
  union {
    struct {
      UINT MultiEngineAware : 1;
      UINT VSyncPowerSaveAware : 1;
      UINT PreemptionAware : 1;
      UINT NoDmaPatching : 1;
      UINT CancelCommandAware : 1;
      UINT No64BitAtomics : 1;
      UINT LowIrqlPreemptCommand : 1;
      UINT HwQueuePacketCap : 4;
      UINT NativeGpuFence : 1;
      UINT OptimizedNativeFenceSignaledInterrupt : 1;
#if ...
      UINT Reserved : 19;
#elif
      UINT Reserved : 21;
#elif
      UINT Reserved : 25;
#elif
      UINT Reserved : 27;
#else
      UINT Reserved : 30;
#endif
    };
    UINT Value;
  };
} DXGK_VIDSCHCAPS;