NTSTATUS SeSetSecurityDescriptorInfoEx(
  [in, optional] PVOID                 Object,
  [in]           PSECURITY_INFORMATION SecurityInformation,
                 PSECURITY_DESCRIPTOR  ModificationDescriptor,
  [in, out]      PSECURITY_DESCRIPTOR  *ObjectsSecurityDescriptor,
  [in]           ULONG                 AutoInheritFlags,
  [in]           POOL_TYPE             PoolType,
  [in]           PGENERIC_MAPPING      GenericMapping
);