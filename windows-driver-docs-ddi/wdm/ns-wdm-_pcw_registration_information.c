typedef struct _PCW_REGISTRATION_INFORMATION {
  ULONG                   Version;
  PCUNICODE_STRING        Name;
  ULONG                   CounterCount;
  PPCW_COUNTER_DESCRIPTOR Counters;
  PPCW_CALLBACK           Callback;
  PVOID                   CallbackContext;
  PCW_REGISTRATION_FLAGS  Flags;
} PCW_REGISTRATION_INFORMATION, *PPCW_REGISTRATION_INFORMATION;