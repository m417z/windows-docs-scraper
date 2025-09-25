BOOL CreatePrivateObjectSecurityEx(
  [in, optional] PSECURITY_DESCRIPTOR ParentDescriptor,
  [in, optional] PSECURITY_DESCRIPTOR CreatorDescriptor,
  [out]          PSECURITY_DESCRIPTOR *NewDescriptor,
  [in, optional] GUID                 *ObjectType,
  [in]           BOOL                 IsContainerObject,
  [in]           ULONG                AutoInheritFlags,
  [in, optional] HANDLE               Token,
  [in]           PGENERIC_MAPPING     GenericMapping
);