typedef union _WHEA_XPF_CACHE_CHECK {
  struct {
    ULONGLONG TransactionTypeValid : 1;
    ULONGLONG OperationValid : 1;
    ULONGLONG LevelValid : 1;
    ULONGLONG ProcessorContextCorruptValid : 1;
    ULONGLONG UncorrectedValid : 1;
    ULONGLONG PreciseIPValid : 1;
    ULONGLONG RestartableIPValid : 1;
    ULONGLONG OverflowValid : 1;
    ULONGLONG ReservedValid : 8;
    ULONGLONG TransactionType : 2;
    ULONGLONG Operation : 4;
    ULONGLONG Level : 3;
    ULONGLONG ProcessorContextCorrupt : 1;
    ULONGLONG Uncorrected : 1;
    ULONGLONG PreciseIP : 1;
    ULONGLONG RestartableIP : 1;
    ULONGLONG Overflow : 1;
    ULONGLONG Reserved : 34;
  } DUMMYSTRUCTNAME;
  ULONGLONG XpfCacheCheck;
} WHEA_XPF_CACHE_CHECK, *PWHEA_XPF_CACHE_CHECK;