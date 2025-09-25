NTSYSCALLAPI NTSTATUS ZwSetInformationEnlistment(
  [in] HANDLE                       EnlistmentHandle,
  [in] ENLISTMENT_INFORMATION_CLASS EnlistmentInformationClass,
  [in] PVOID                        EnlistmentInformation,
  [in] ULONG                        EnlistmentInformationLength
);