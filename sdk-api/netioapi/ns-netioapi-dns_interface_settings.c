typedef struct _DNS_INTERFACE_SETTINGS {
  ULONG   Version;
  ULONG64 Flags;
  PWSTR   Domain;
  PWSTR   NameServer;
  PWSTR   SearchList;
  ULONG   RegistrationEnabled;
  ULONG   RegisterAdapterName;
  ULONG   EnableLLMNR;
  ULONG   QueryAdapterName;
  PWSTR   ProfileNameServer;
} DNS_INTERFACE_SETTINGS;