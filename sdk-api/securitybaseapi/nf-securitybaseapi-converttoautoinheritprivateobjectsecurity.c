BOOL ConvertToAutoInheritPrivateObjectSecurity(
  [in, optional] PSECURITY_DESCRIPTOR ParentDescriptor,
  [in]           PSECURITY_DESCRIPTOR CurrentSecurityDescriptor,
  [out]          PSECURITY_DESCRIPTOR *NewSecurityDescriptor,
  [in, optional] GUID                 *ObjectType,
  [in]           BOOLEAN              IsDirectoryObject,
  [in]           PGENERIC_MAPPING     GenericMapping
);