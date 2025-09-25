BOOL SetPrivateObjectSecurity(
  [in]           SECURITY_INFORMATION SecurityInformation,
  [in]           PSECURITY_DESCRIPTOR ModificationDescriptor,
  [in, out]      PSECURITY_DESCRIPTOR *ObjectsSecurityDescriptor,
  [in]           PGENERIC_MAPPING     GenericMapping,
  [in, optional] HANDLE               Token
);