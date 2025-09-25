typedef struct _KBUGCHECK_SECONDARY_DUMP_DATA_EX {
  PVOID     InBuffer;
  ULONG     InBufferLength;
  ULONG     MaximumAllowed;
  GUID      Guid;
  PVOID     OutBuffer;
  ULONG     OutBufferLength;
  PVOID     Context;
  ULONG     Flags;
  ULONG     DumpType;
  ULONG     BugCheckCode;
  ULONG_PTR BugCheckParameter1;
  ULONG_PTR BugCheckParameter2;
  ULONG_PTR BugCheckParameter3;
  ULONG_PTR BugCheckParameter4;
} KBUGCHECK_SECONDARY_DUMP_DATA_EX, *PKBUGCHECK_SECONDARY_DUMP_DATA_EX;