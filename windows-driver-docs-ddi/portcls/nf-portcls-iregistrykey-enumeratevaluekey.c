NTSTATUS EnumerateValueKey(
  [in]  ULONG                       Index,
  [in]  KEY_VALUE_INFORMATION_CLASS KeyValueInformationClass,
  [out] PVOID                       KeyValueInformation,
  [in]  ULONG                       Length,
  [out] PULONG                      ResultLength
);