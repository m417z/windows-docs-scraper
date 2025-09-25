typedef struct _PEP_PROCESSOR_FEEDBACK_COUNTER {
  struct {
    ULONG Affinitized : 1;
    ULONG Type : 2;
    ULONG Counter : 4;
    ULONG DiscountIdle : 1;
    ULONG Reserved : 24;
  };
  ULONG  NominalRate;
} PEP_PROCESSOR_FEEDBACK_COUNTER, *PPEP_PROCESSOR_FEEDBACK_COUNTER;