PORTCLASSAPI NTSTATUS PcNewRegistryKey(
  [out]           PREGISTRYKEY       *OutRegistryKey,
  [in, optional]  PUNKNOWN           OuterUnknown,
  [in]            ULONG              RegistryKeyType,
  [in]            ACCESS_MASK        DesiredAccess,
  [in, optional]  PVOID              DeviceObject,
  [in, optional]  PVOID              SubDevice,
  [in, optional]  POBJECT_ATTRIBUTES ObjectAttributes,
  [in, optional]  ULONG              CreateOptions,
  [out, optional] PULONG             Disposition
);