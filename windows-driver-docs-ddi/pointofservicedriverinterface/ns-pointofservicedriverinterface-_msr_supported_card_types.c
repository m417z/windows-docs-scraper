typedef struct _MSR_SUPPORTED_CARD_TYPES {
  unsigned char Count;
  unsigned int  CardTypes[MSR_CARD_TYPE_MAX_COUNT];
} MSR_SUPPORTED_CARD_TYPES, *PMSR_SUPPORTED_CARD_TYPES;