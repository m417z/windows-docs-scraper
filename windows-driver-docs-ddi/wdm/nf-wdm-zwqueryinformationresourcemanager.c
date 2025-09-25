NTSYSCALLAPI NTSTATUS ZwQueryInformationResourceManager(
  [in]            HANDLE                            ResourceManagerHandle,
  [in]            RESOURCEMANAGER_INFORMATION_CLASS ResourceManagerInformationClass,
  [out]           PVOID                             ResourceManagerInformation,
  [in]            ULONG                             ResourceManagerInformationLength,
  [out, optional] PULONG                            ReturnLength
);