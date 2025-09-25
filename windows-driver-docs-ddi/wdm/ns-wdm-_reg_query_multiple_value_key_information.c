typedef struct _REG_QUERY_MULTIPLE_VALUE_KEY_INFORMATION {
  PVOID            Object;
  PKEY_VALUE_ENTRY ValueEntries;
  ULONG            EntryCount;
  PVOID            ValueBuffer;
  PULONG           BufferLength;
  PULONG           RequiredBufferLength;
  PVOID            CallContext;
  PVOID            ObjectContext;
  PVOID            Reserved;
} REG_QUERY_MULTIPLE_VALUE_KEY_INFORMATION, *PREG_QUERY_MULTIPLE_VALUE_KEY_INFORMATION;