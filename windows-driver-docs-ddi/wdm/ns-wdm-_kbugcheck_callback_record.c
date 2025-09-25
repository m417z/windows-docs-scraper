typedef struct _KBUGCHECK_CALLBACK_RECORD {
  LIST_ENTRY                  Entry;
  PKBUGCHECK_CALLBACK_ROUTINE CallbackRoutine;
  PVOID                       Buffer;
  ULONG                       Length;
  PUCHAR                      Component;
  ULONG_PTR                   Checksum;
  UCHAR                       State;
} KBUGCHECK_CALLBACK_RECORD, *PKBUGCHECK_CALLBACK_RECORD;