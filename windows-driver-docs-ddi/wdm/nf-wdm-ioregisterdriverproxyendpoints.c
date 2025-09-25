NTSTATUS IoRegisterDriverProxyEndpoints(
  PDRIVER_PROXY_EXTENSION            DriverProxyExtension,
  PDRIVER_PROXY_ENDPOINT_INFORMATION EndpointInfo,
  ULONG                              Count,
  PDRIVER_PROXY_REGISTER_CALLBACK    PhasedCallback,
  PVOID                              Context
);