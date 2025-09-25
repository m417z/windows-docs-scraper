typedef struct _STOR_LIST_ENTRY {
  struct _STOR_LIST_ENTRY *Flink;
  struct _STOR_LIST_ENTRY *Blink;
} STOR_LIST_ENTRY, *PSTOR_LIST_ENTRY;