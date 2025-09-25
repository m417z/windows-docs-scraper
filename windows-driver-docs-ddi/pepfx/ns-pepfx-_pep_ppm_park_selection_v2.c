typedef struct _PEP_PPM_PARK_SELECTION_V2 {
  [in]     ULONG                          AdditionalUnparkedProcessors;
  [in]     ULONG                          Count;
  [in/out] PPEP_PROCESSOR_PARK_PREFERENCE Processors;
           ULONGLONG                      EvaluationTime;
           UCHAR                          EvaluationType;
} PEP_PPM_PARK_SELECTION_V2, *PPEP_PPM_PARK_SELECTION_V2;