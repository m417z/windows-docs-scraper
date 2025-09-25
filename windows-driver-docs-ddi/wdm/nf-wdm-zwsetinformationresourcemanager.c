NTSYSCALLAPI NTSTATUS ZwSetInformationResourceManager(
  HANDLE                            ResourceManagerHandle,
  RESOURCEMANAGER_INFORMATION_CLASS ResourceManagerInformationClass,
  PVOID                             ResourceManagerInformation,
  ULONG                             ResourceManagerInformationLength
);