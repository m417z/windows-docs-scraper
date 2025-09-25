NTSTATUS LsaQueryInformationPolicy(
  [in]  LSA_HANDLE               PolicyHandle,
  [in]  POLICY_INFORMATION_CLASS InformationClass,
  [out] PVOID                    *Buffer
);