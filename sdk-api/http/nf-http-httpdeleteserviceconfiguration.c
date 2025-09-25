HTTPAPI_LINKAGE ULONG HttpDeleteServiceConfiguration(
  [in] HANDLE                 ServiceHandle,
  [in] HTTP_SERVICE_CONFIG_ID ConfigId,
  [in] PVOID                  pConfigInformation,
  [in] ULONG                  ConfigInformationLength,
  [in] LPOVERLAPPED           pOverlapped
);