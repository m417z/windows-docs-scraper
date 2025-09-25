NTSTATUS ObGetObjectSecurity(
  [in]  PVOID                Object,
  [out] PSECURITY_DESCRIPTOR *SecurityDescriptor,
  [out] PBOOLEAN             MemoryAllocated
);