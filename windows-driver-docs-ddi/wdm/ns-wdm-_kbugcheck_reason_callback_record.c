typedef struct _KBUGCHECK_REASON_CALLBACK_RECORD {
  LIST_ENTRY                         Entry;
  PKBUGCHECK_REASON_CALLBACK_ROUTINE CallbackRoutine;
  PUCHAR                             Component;
  ULONG_PTR                          Checksum;
  KBUGCHECK_CALLBACK_REASON          Reason;
  UCHAR                              State;
} KBUGCHECK_REASON_CALLBACK_RECORD, *PKBUGCHECK_REASON_CALLBACK_RECORD;