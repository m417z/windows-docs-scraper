typedef struct _KBUGCHECK_TRIAGE_DUMP_DATA {
  PKTRIAGE_DUMP_DATA_ARRAY DataArray;
  ULONG                    Flags;
  ULONG                    MaxVirtMemSize;
  ULONG                    BugCheckCode;
  ULONG_PTR                BugCheckParameter1;
  ULONG_PTR                BugCheckParameter2;
  ULONG_PTR                BugCheckParameter3;
  ULONG_PTR                BugCheckParameter4;
} KBUGCHECK_TRIAGE_DUMP_DATA, *PKBUGCHECK_TRIAGE_DUMP_DATA;