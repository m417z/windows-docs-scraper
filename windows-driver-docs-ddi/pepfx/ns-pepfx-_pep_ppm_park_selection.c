typedef struct _PEP_PPM_PARK_SELECTION {
  [in]     ULONG                          AdditionalUnparkedProcessors;
  [in]     ULONG                          Count;
  [in/out] PPEP_PROCESSOR_PARK_PREFERENCE Processors;
} PEP_PPM_PARK_SELECTION, *PPEP_PPM_PARK_SELECTION;