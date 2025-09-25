NTSTATUS NewSubKey(
  [out]           IRegistryKey    **RegistrySubKey,
  [in]            PUNKNOWN        OuterUnknown,
  [in]            ACCESS_MASK     DesiredAccess,
  [in]            PUNICODE_STRING SubKeyName,
  [in]            ULONG           CreateOptions,
  [out, optional] PULONG          Disposition
);