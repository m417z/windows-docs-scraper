typedef struct _DNS_INTERFACE_SETTINGS3 {
  ULONG               Version;
  ULONG64             Flags;
  PWSTR               Domain;
  PWSTR               NameServer;
  PWSTR               SearchList;
  ULONG               RegistrationEnabled;
  ULONG               RegisterAdapterName;
  ULONG               EnableLLMNR;
  ULONG               QueryAdapterName;
  PWSTR               ProfileNameServer;
  ULONG               DisableUnconstrainedQueries;
  PWSTR               SupplementalSearchList;
  ULONG               cServerProperties;
  DNS_SERVER_PROPERTY *ServerProperties;
  ULONG               cProfileServerProperties;
  DNS_SERVER_PROPERTY *ProfileServerProperties;
} DNS_INTERFACE_SETTINGS3;