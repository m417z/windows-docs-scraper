typedef struct _DNS_INTERFACE_SETTINGS_EX {
  DNS_INTERFACE_SETTINGS SettingsV1;
  ULONG                  DisableUnconstrainedQueries;
  PWSTR                  SupplementalSearchList;
} DNS_INTERFACE_SETTINGS_EX;