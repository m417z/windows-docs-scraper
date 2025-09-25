typedef union _WHEA_MEMORY_ERROR_SECTION_VALIDBITS {
  struct {
    ULONGLONG ErrorStatus : 1;
    ULONGLONG PhysicalAddress : 1;
    ULONGLONG PhysicalAddressMask : 1;
    ULONGLONG Node : 1;
    ULONGLONG Card : 1;
    ULONGLONG Module : 1;
    ULONGLONG Bank : 1;
    ULONGLONG Device : 1;
    ULONGLONG Row : 1;
    ULONGLONG Column : 1;
    ULONGLONG BitPosition : 1;
    ULONGLONG RequesterId : 1;
    ULONGLONG ResponderId : 1;
    ULONGLONG TargetId : 1;
    ULONGLONG ErrorType : 1;
    ULONGLONG RankNumber : 1;
    ULONGLONG CardHandle : 1;
    ULONGLONG ModuleHandle : 1;
    ULONGLONG ExtendedRow : 1;
    ULONGLONG BankGroup : 1;
    ULONGLONG BankAddress : 1;
    ULONGLONG ChipIdentification : 1;
    ULONGLONG Reserved : 42;
  } DUMMYSTRUCTNAME;
  ULONGLONG ValidBits;
} WHEA_MEMORY_ERROR_SECTION_VALIDBITS, *PWHEA_MEMORY_ERROR_SECTION_VALIDBITS;