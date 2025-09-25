BOOL CreatePrivateObjectSecurity(
  [in, optional] PSECURITY_DESCRIPTOR ParentDescriptor,
  [in, optional] PSECURITY_DESCRIPTOR CreatorDescriptor,
  [out]          PSECURITY_DESCRIPTOR *NewDescriptor,
  [in]           BOOL                 IsDirectoryObject,
  [in, optional] HANDLE               Token,
  [in]           PGENERIC_MAPPING     GenericMapping
);