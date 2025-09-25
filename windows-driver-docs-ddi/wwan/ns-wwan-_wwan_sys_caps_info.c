typedef struct _WWAN_SYS_CAPS_INFO {
  ULONG   NumberOfExecutors;
  ULONG   NumberOfSlots;
  ULONG   Concurrency;
  ULONG64 ModemID;
} WWAN_SYS_CAPS_INFO, *PWWAN_SYS_CAPS_INFO;