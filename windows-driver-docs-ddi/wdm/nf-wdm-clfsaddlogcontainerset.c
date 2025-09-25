CLFSUSER_API NTSTATUS ClfsAddLogContainerSet(
  [in]           PLOG_FILE_OBJECT plfoLog,
  [in]           USHORT           cContainers,
  [in, optional] PULONGLONG       pcbContainer,
  [in]           PUNICODE_STRING  rguszContainerPath
);