typedef struct _WHEA_PSHED_PLUGIN_LOAD_EVENT {
  WHEA_EVENT_LOG_ENTRY WheaEventLogEntry;
  WCHAR                PluginName[WHEA_ERROR_TEXT_LEN];
  ULONG                MajorVersion;
  ULONG                MinorVersion;
} WHEA_PSHED_PLUGIN_LOAD_EVENT, *PWHEA_PSHED_PLUGIN_LOAD_EVENT;