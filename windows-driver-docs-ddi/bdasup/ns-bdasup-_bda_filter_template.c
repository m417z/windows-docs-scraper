typedef struct _BDA_FILTER_TEMPLATE {
  const KSFILTER_DESCRIPTOR *pFilterDescriptor;
  ULONG                     ulcPinPairs;
  const BDA_PIN_PAIRING     *pPinPairs;
} BDA_FILTER_TEMPLATE, *PBDA_FILTER_TEMPLATE;