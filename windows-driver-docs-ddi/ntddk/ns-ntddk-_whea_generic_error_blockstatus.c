typedef union _WHEA_GENERIC_ERROR_BLOCKSTATUS {
  struct {
    ULONG UncorrectableError : 1;
    ULONG CorrectableError : 1;
    ULONG MultipleUncorrectableErrors : 1;
    ULONG MultipleCorrectableErrors : 1;
    ULONG ErrorDataEntryCount : 10;
    ULONG Reserved : 18;
  } DUMMYSTRUCTNAME;
  ULONG  AsULONG;
} WHEA_GENERIC_ERROR_BLOCKSTATUS, *PWHEA_GENERIC_ERROR_BLOCKSTATUS;