NTSYSAPI NTSTATUS ZwQueryValueKey(
  [in]            HANDLE                      KeyHandle,
  [in]            PUNICODE_STRING             ValueName,
  [in]            KEY_VALUE_INFORMATION_CLASS KeyValueInformationClass,
  [out, optional] PVOID                       KeyValueInformation,
  [in]            ULONG                       Length,
  [out]           PULONG                      ResultLength
);