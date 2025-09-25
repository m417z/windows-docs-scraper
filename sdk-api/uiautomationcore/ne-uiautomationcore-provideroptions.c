typedef enum ProviderOptions {
  ProviderOptions_ClientSideProvider = 0x1,
  ProviderOptions_ServerSideProvider = 0x2,
  ProviderOptions_NonClientAreaProvider = 0x4,
  ProviderOptions_OverrideProvider = 0x8,
  ProviderOptions_ProviderOwnsSetFocus = 0x10,
  ProviderOptions_UseComThreading = 0x20,
  ProviderOptions_RefuseNonClientSupport = 0x40,
  ProviderOptions_HasNativeIAccessible = 0x80,
  ProviderOptions_UseClientCoordinates = 0x100
} ;