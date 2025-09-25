typedef union _WHEA_XPF_BUS_CHECK {
  struct {
    ULONGLONG TransactionTypeValid : 1;
    ULONGLONG OperationValid : 1;
    ULONGLONG LevelValid : 1;
    ULONGLONG ProcessorContextCorruptValid : 1;
    ULONGLONG UncorrectedValid : 1;
    ULONGLONG PreciseIPValid : 1;
    ULONGLONG RestartableIPValid : 1;
    ULONGLONG OverflowValid : 1;
    ULONGLONG ParticipationValid : 1;
    ULONGLONG TimeoutValid : 1;
    ULONGLONG AddressSpaceValid : 1;
    ULONGLONG ReservedValid : 5;
    ULONGLONG TransactionType : 2;
    ULONGLONG Operation : 4;
    ULONGLONG Level : 3;
    ULONGLONG ProcessorContextCorrupt : 1;
    ULONGLONG Uncorrected : 1;
    ULONGLONG PreciseIP : 1;
    ULONGLONG RestartableIP : 1;
    ULONGLONG Overflow : 1;
    ULONGLONG Participation : 2;
    ULONGLONG Timeout : 1;
    ULONGLONG AddressSpace : 2;
    ULONGLONG Reserved : 29;
  } DUMMYSTRUCTNAME;
  ULONGLONG XpfBusCheck;
} WHEA_XPF_BUS_CHECK, *PWHEA_XPF_BUS_CHECK;