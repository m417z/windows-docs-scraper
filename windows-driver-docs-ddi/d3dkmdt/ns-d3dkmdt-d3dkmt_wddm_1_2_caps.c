typedef struct _D3DKMT_WDDM_1_2_CAPS {
  D3DKMDT_PREEMPTION_CAPS PreemptionCaps;
  union {
    struct {
      UINT SupportNonVGA : 1;
      UINT SupportSmoothRotation : 1;
      UINT SupportPerEngineTDR : 1;
      UINT SupportKernelModeCommandBuffer : 1;
      UINT SupportCCD : 1;
      UINT SupportSoftwareDeviceBitmaps : 1;
      UINT SupportGammaRamp : 1;
      UINT SupportHWCursor : 1;
      UINT SupportHWVSync : 1;
      UINT SupportSurpriseRemovalInHibernation : 1;
      UINT Reserved : 22;
    };
    UINT Value;
  };
} D3DKMT_WDDM_1_2_CAPS;