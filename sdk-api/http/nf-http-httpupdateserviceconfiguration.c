HTTPAPI_LINKAGE ULONG HttpUpdateServiceConfiguration(
  [in] HANDLE                 Handle,
  [in] HTTP_SERVICE_CONFIG_ID ConfigId,
  [in] PVOID                  ConfigInfo,
  [in] ULONG                  ConfigInfoLength,
  [in] LPOVERLAPPED           Overlapped
);