NTSYSAPI NTSTATUS ZwEnumerateKey(
  [in]            HANDLE                KeyHandle,
  [in]            ULONG                 Index,
  [in]            KEY_INFORMATION_CLASS KeyInformationClass,
  [out, optional] PVOID                 KeyInformation,
  [in]            ULONG                 Length,
  [out]           PULONG                ResultLength
);