typedef DWORD (WINAPI *HS_HOST_UPDATE_CONFIGURATION_COMPLETION)(
  _In_ HANDLE            hPluginContext,
  _In_ eHS_UPDATE_RESULT UpdateResult
);