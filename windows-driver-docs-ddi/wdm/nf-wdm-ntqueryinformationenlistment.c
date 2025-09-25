__kernel_entry NTSYSCALLAPI NTSTATUS NtQueryInformationEnlistment(
  [in]            HANDLE                       EnlistmentHandle,
  [in]            ENLISTMENT_INFORMATION_CLASS EnlistmentInformationClass,
  [out]           PVOID                        EnlistmentInformation,
  [in]            ULONG                        EnlistmentInformationLength,
  [out, optional] PULONG                       ReturnLength
);