typedef struct _STACK_SRC_INFO {
  PCWSTR ImagePath;
  PCWSTR ModuleName;
  PCWSTR Function;
  ULONG  Displacement;
  ULONG  Row;
  ULONG  Column;
} STACK_SRC_INFO, *PSTACK_SRC_INFO;