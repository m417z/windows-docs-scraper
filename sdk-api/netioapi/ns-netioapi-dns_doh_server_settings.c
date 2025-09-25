typedef struct _DNS_DOH_SERVER_SETTINGS {
#if ...
  PWSTR   Template;
#else
  PWSTR   Template;
#endif
  ULONG64 Flags;
} DNS_DOH_SERVER_SETTINGS;