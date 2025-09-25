NTSTATUS NewRegistryKey(
  PREGISTRYKEY       *OutRegistryKey,
  PUNKNOWN           OuterUnknown,
  ULONG              RegistryKeyType,
  ACCESS_MASK        DesiredAccess,
  POBJECT_ATTRIBUTES ObjectAttributes,
  ULONG              CreateOptions,
  PULONG             Disposition
);