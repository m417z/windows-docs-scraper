NTSTATUS SeSetSecurityDescriptorInfo(
  [in, optional] PVOID                 Object,
  [in]           PSECURITY_INFORMATION SecurityInformation,
                 PSECURITY_DESCRIPTOR  ModificationDescriptor,
  [in, out]      PSECURITY_DESCRIPTOR  *ObjectsSecurityDescriptor,
  [in]           POOL_TYPE             PoolType,
  [in]           PGENERIC_MAPPING      GenericMapping
);