typedef struct _PEP_PPM_QUERY_IDLE_STATES {
  [in]  ULONG                    Count;
  [out] ULONG                    MaximumCoordinatedProcessors;
        PEP_PROCESSOR_IDLE_STATE IdleStates[ANYSIZE_ARRAY];
} PEP_PPM_QUERY_IDLE_STATES, *PPEP_PPM_QUERY_IDLE_STATES;