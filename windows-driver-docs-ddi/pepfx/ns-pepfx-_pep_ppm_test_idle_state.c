typedef struct _PEP_PPM_TEST_IDLE_STATE {
        ULONG ProcessorState;
  [in]  ULONG PlatformState;
  [out] ULONG VetoReason;
} PEP_PPM_TEST_IDLE_STATE, *PPEP_PPM_TEST_IDLE_STATE;