typedef struct _WHEA_PSHED_PLUGIN_REGISTRATION_PACKET_V2 {
  ULONG                       Length;
  ULONG                       Version;
  PVOID                       Context;
  ULONG                       FunctionalAreaMask;
  ULONG                       Reserved;
  WHEA_PSHED_PLUGIN_CALLBACKS Callbacks;
  PVOID                       PluginHandle;
} WHEA_PSHED_PLUGIN_REGISTRATION_PACKET_V2;