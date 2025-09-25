typedef struct _D3DKMT_ADAPTERTYPE {
  union {
    struct {
      UINT RenderSupported : 1;
      UINT DisplaySupported : 1;
      UINT SoftwareDevice : 1;
      UINT PostDevice : 1;
      UINT HybridDiscrete : 1;
      UINT HybridIntegrated : 1;
      UINT IndirectDisplayDevice : 1;
      UINT Paravirtualized : 1;
      UINT ACGSupported : 1;
      UINT SupportSetTimingsFromVidPn : 1;
      UINT Detachable : 1;
      UINT ComputeOnly : 1;
      UINT Prototype : 1;
      UINT RuntimePowerManagement : 1;
#if ...
      UINT Reserved : 18;
#elif
      UINT Reserved : 19;
#elif
      UINT Reserved : 21;
#elif
      UINT Reserved : 25;
#else
      UINT Reserved : 28;
#endif
    };
    UINT Value;
  };
} D3DKMT_ADAPTERTYPE;