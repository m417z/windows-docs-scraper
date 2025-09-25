typedef union _WHEA_XPF_MS_CHECK {
  struct {
    ULONGLONG ErrorTypeValid : 1;
    ULONGLONG ProcessorContextCorruptValid : 1;
    ULONGLONG UncorrectedValid : 1;
    ULONGLONG PreciseIPValid : 1;
    ULONGLONG RestartableIPValid : 1;
    ULONGLONG OverflowValid : 1;
    ULONGLONG ReservedValue : 10;
    ULONGLONG ErrorType : 3;
    ULONGLONG ProcessorContextCorrupt : 1;
    ULONGLONG Uncorrected : 1;
    ULONGLONG PreciseIP : 1;
    ULONGLONG RestartableIP : 1;
    ULONGLONG Overflow : 1;
    ULONGLONG Reserved : 40;
  } DUMMYSTRUCTNAME;
  ULONGLONG XpfMsCheck;
} WHEA_XPF_MS_CHECK, *PWHEA_XPF_MS_CHECK;