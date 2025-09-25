NTSTATUS IoGetContainerInformation(
  [in]           IO_CONTAINER_INFORMATION_CLASS InformationClass,
  [in, optional] PVOID                          ContainerObject,
  [in, out]      PVOID                          Buffer,
  [in]           ULONG                          BufferLength
);