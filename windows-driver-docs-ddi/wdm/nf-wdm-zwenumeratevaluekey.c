NTSYSAPI NTSTATUS ZwEnumerateValueKey(
  [in]            HANDLE                      KeyHandle,
  [in]            ULONG                       Index,
  [in]            KEY_VALUE_INFORMATION_CLASS KeyValueInformationClass,
  [out, optional] PVOID                       KeyValueInformation,
  [in]            ULONG                       Length,
  [out]           PULONG                      ResultLength
);