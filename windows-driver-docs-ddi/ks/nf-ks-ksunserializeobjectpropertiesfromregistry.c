KSDDKAPI NTSTATUS KsUnserializeObjectPropertiesFromRegistry(
  [in]           PFILE_OBJECT    FileObject,
  [in, optional] HANDLE          ParentKey,
  [in, optional] PUNICODE_STRING RegistryPath
);