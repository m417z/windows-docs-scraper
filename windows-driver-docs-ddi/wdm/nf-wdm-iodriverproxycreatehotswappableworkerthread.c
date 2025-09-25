NTSTATUS IoDriverProxyCreateHotSwappableWorkerThread(
  PDRIVER_PROXY_EXTENSION                            DriverProxyExtension,
  PHANDLE                                            ThreadHandle,
  ULONG                                              DesiredAccess,
  POBJECT_ATTRIBUTES                                 ObjectAttributes,
  HANDLE                                             ProcessHandle,
  PCLIENT_ID                                         ClientId,
  PDRIVER_PROXY_HOTSWAP_WORKER_ROUTINE_START_CONTEXT WorkerStartContext
);