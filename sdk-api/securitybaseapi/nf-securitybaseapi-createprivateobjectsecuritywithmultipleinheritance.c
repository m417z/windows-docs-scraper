BOOL CreatePrivateObjectSecurityWithMultipleInheritance(
  [in, optional] PSECURITY_DESCRIPTOR ParentDescriptor,
  [in, optional] PSECURITY_DESCRIPTOR CreatorDescriptor,
  [out]          PSECURITY_DESCRIPTOR *NewDescriptor,
  [in, optional] GUID                 **ObjectTypes,
  [in]           ULONG                GuidCount,
  [in]           BOOL                 IsContainerObject,
  [in]           ULONG                AutoInheritFlags,
  [in, optional] HANDLE               Token,
  [in]           PGENERIC_MAPPING     GenericMapping
);