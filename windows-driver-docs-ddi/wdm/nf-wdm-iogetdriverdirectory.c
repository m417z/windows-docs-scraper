NTSTATUS IoGetDriverDirectory(
  [_In_]  PDRIVER_OBJECT        DriverObject,
  [_In_]  DRIVER_DIRECTORY_TYPE DirectoryType,
  [_In_]  ULONG                 Flags,
  [_Out_] PHANDLE               DriverDirectoryHandle
);