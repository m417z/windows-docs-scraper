CLFSUSER_API NTSTATUS ClfsRemoveLogContainerSet(
  [in] PLOG_FILE_OBJECT plfoLog,
  [in] USHORT           cContainers,
  [in] PUNICODE_STRING  rgwszContainerPath,
  [in] BOOLEAN          fForce
);