typedef struct _DXGK_DRIVERCAPS {
  [out] PHYSICAL_ADDRESS                   HighestAcceptableAddress;
  [out] UINT                               MaxAllocationListSlotId;
  [out] SIZE_T                             ApertureSegmentCommitLimit;
  [out] UINT                               MaxPointerWidth;
  [out] UINT                               MaxPointerHeight;
  [out] DXGK_POINTERFLAGS                  PointerCaps;
  [out] UINT                               InterruptMessageNumber;
  [out] UINT                               NumberOfSwizzlingRanges;
  [out] UINT                               MaxOverlays;
  union {
    [out] DXGK_GAMMARAMPCAPS      GammaRampCaps;
    [out] DXGK_COLORTRANSFORMCAPS ColorTransformCaps;
  };
  [out] DXGK_PRESENTATIONCAPS              PresentationCaps;
  [out] UINT                               MaxQueuedFlipOnVSync;
  [out] DXGK_FLIPCAPS                      FlipCaps;
  [out] DXGK_VIDSCHCAPS                    SchedulingCaps;
  [out] DXGK_VIDMMCAPS                     MemoryManagementCaps;
  [out] DXGK_GPUENGINETOPOLOGY             GpuEngineTopology;
  [out] DXGK_WDDMVERSION                   WDDMVersion;
        DXGK_VIRTUALADDRESSCAPS_DEPRECATED Reserved;
        DXGK_DMABUFFERCAPS_DEPRECATED      Reserved1;
  [out] D3DKMDT_PREEMPTION_CAPS            PreemptionCaps;
  [out] BOOLEAN                            SupportNonVGA;
  [out] BOOLEAN                            SupportSmoothRotation;
  [out] BOOLEAN                            SupportPerEngineTDR;
  [out] BOOLEAN                            SupportDirectFlip;
  [out] BOOLEAN                            SupportMultiPlaneOverlay;
  [out] BOOLEAN                            SupportRuntimePowerManagement;
  [out] BOOLEAN                            SupportSurpriseRemovalInHibernation;
  [out] BOOLEAN                            HybridDiscrete;
  [out] UINT                               MaxOverlayPlanes;
        BOOLEAN                            HybridIntegrated;
        D3DGPU_VIRTUAL_ADDRESS             InternalGpuVirtualAddressRangeStart;
        D3DGPU_VIRTUAL_ADDRESS             InternalGpuVirtualAddressRangeEnd;
        BOOLEAN                            SupportSurpriseRemoval;
  [out] BOOLEAN                            SupportMultiPlaneOverlayImmediateFlip;
  [out] BOOLEAN                            CursorScaledWithMultiPlaneOverlayPlane0;
        BOOLEAN                            HybridAcpiChainingRequired;
  [out] UINT                               MaxQueuedMultiPlaneOverlayFlipVSync;
  union {
    struct {
      UINT SupportContextlessPresent : 1;
      UINT Detachable : 1;
      UINT VirtualGpuOnly : 1;
      UINT ComputeOnly : 1;
      UINT IndependentVidPnVSyncControl : 1;
      UINT NoHybridDiscreteDListDllSupport : 1;
      UINT DisplayableSupport : 1;
      UINT NoHybridDiscreteDListDllMuxSupport : 1;
      UINT CursorDoesNotSupportXorBlendWithMultiPlaneOverlay : 1;
#if ...
      UINT Reserved : 23;
#elif
      UINT Reserved : 25;
#elif
      UINT Reserved : 26;
#elif
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
  } MiscCaps;
        UINT                               MaxHwQueuedFlips;
        DXGK_HWQUEUEDFLIP_CAPS             HwQueuedFlipCaps;
} DXGK_DRIVERCAPS;