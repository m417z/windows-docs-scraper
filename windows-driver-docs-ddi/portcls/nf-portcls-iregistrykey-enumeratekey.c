NTSTATUS EnumerateKey(
  [in]  ULONG                 Index,
  [in]  KEY_INFORMATION_CLASS KeyInformationClass,
  [out] PVOID                 KeyInformation,
  [in]  ULONG                 Length,
  [out] PULONG                ResultLength
);