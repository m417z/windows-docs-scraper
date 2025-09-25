typedef struct _D3DKMT_WDDM_1_3_CAPS {
  union {
    struct {
      UINT SupportMiracast : 1;
      UINT IsHybridIntegratedGPU : 1;
      UINT IsHybridDiscreteGPU : 1;
      UINT SupportPowerManagementPStates : 1;
      UINT SupportVirtualModes : 1;
      UINT SupportCrossAdapterResource : 1;
      UINT Reserved : 26;
    };
    UINT Value;
  };
} D3DKMT_WDDM_1_3_CAPS;