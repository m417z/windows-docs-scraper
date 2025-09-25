NTSTATUS WdfRegistryCreateKey(
  [in, optional]  WDFKEY                 ParentKey,
  [in]            PCUNICODE_STRING       KeyName,
  [in]            ACCESS_MASK            DesiredAccess,
  [in]            ULONG                  CreateOptions,
  [out, optional] PULONG                 CreateDisposition,
  [in, optional]  PWDF_OBJECT_ATTRIBUTES KeyAttributes,
  [out]           WDFKEY                 *Key
);