__kernel_entry NTSYSCALLAPI NTSTATUS NtSetInformationResourceManager(
  HANDLE                            ResourceManagerHandle,
  RESOURCEMANAGER_INFORMATION_CLASS ResourceManagerInformationClass,
  PVOID                             ResourceManagerInformation,
  ULONG                             ResourceManagerInformationLength
);