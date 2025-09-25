NTSTATUS SeAssignSecurity(
  [in, optional] PSECURITY_DESCRIPTOR      ParentDescriptor,
  [in, optional] PSECURITY_DESCRIPTOR      ExplicitDescriptor,
  [out]          PSECURITY_DESCRIPTOR      *NewDescriptor,
  [in]           BOOLEAN                   IsDirectoryObject,
  [in]           PSECURITY_SUBJECT_CONTEXT SubjectContext,
  [in]           PGENERIC_MAPPING          GenericMapping,
  [in]           POOL_TYPE                 PoolType
);