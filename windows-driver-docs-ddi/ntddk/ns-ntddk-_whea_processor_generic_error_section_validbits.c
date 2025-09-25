typedef union _WHEA_PROCESSOR_GENERIC_ERROR_SECTION_VALIDBITS {
  struct {
    ULONGLONG ProcessorType : 1;
    ULONGLONG InstructionSet : 1;
    ULONGLONG ErrorType : 1;
    ULONGLONG Operation : 1;
    ULONGLONG Flags : 1;
    ULONGLONG Level : 1;
    ULONGLONG CPUVersion : 1;
    ULONGLONG CPUBrandString : 1;
    ULONGLONG ProcessorId : 1;
    ULONGLONG TargetAddress : 1;
    ULONGLONG RequesterId : 1;
    ULONGLONG ResponderId : 1;
    ULONGLONG InstructionPointer : 1;
    ULONGLONG NativeModelId : 1;
    ULONGLONG Reserved : 50;
  } DUMMYSTRUCTNAME;
  ULONGLONG ValidBits;
} WHEA_PROCESSOR_GENERIC_ERROR_SECTION_VALIDBITS, *PWHEA_PROCESSOR_GENERIC_ERROR_SECTION_VALIDBITS;