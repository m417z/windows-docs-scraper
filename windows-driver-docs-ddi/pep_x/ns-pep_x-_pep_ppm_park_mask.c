typedef struct _PEP_PPM_PARK_MASK {
  [in]     ULONG                     Count;
  [in]     ULONGLONG                 EvaluationTime;
  [in/out] PPEP_PROCESSOR_PARK_STATE Processors;
} PEP_PPM_PARK_MASK, *PPEP_PPM_PARK_MASK;