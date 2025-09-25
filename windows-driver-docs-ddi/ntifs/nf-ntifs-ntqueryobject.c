__kernel_entry NTSYSCALLAPI NTSTATUS NtQueryObject(
  [in, optional]  HANDLE                   Handle,
  [in]            OBJECT_INFORMATION_CLASS ObjectInformationClass,
  [out, optional] PVOID                    ObjectInformation,
  [in]            ULONG                    ObjectInformationLength,
  [out, optional] PULONG                   ReturnLength
);