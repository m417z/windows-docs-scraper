NTSTATUS WdfDriverOpenPersistentStateRegistryKey(
  [in]           WDFDRIVER              Driver,
  [in]           ACCESS_MASK            DesiredAccess,
  [in, optional] PWDF_OBJECT_ATTRIBUTES KeyAttributes,
  [out]          WDFKEY                 *Key
);