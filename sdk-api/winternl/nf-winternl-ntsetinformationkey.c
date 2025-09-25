__kernel_entry NTSTATUS NtSetInformationKey(
  [in] HANDLE                    KeyHandle,
  [in] KEY_SET_INFORMATION_CLASS KeySetInformationClass,
  [in] PVOID                     KeySetInformation,
  [in] ULONG                     KeySetInformationLength
);