NTSYSAPI NTSTATUS ZwQueryKey(
  [in]            HANDLE                KeyHandle,
  [in]            KEY_INFORMATION_CLASS KeyInformationClass,
  [out, optional] PVOID                 KeyInformation,
  [in]            ULONG                 Length,
  [out]           PULONG                ResultLength
);