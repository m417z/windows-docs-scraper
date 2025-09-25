typedef struct _DXGK_SETVIDPNSOURCEADDRESS_INPUT_FLAGS {
  union {
    struct {
      UINT FlipStereo : 1;
      UINT FlipStereoTemporaryMono : 1;
      UINT FlipStereoPreferRight : 1;
      UINT RetryAtLowerIrql : 1;
      UINT Reserved : 28;
    };
    UINT Value;
  };
} DXGK_SETVIDPNSOURCEADDRESS_INPUT_FLAGS;