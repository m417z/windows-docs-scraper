NTSTATUS IoGetDeviceDirectory(
  [_In_]  PDEVICE_OBJECT        PhysicalDeviceObject,
  [_In_]  DEVICE_DIRECTORY_TYPE DirectoryType,
  [_In_]  ULONG                 Flags,
  [_In_]  PVOID                 Reserved,
  [_Out_] PHANDLE               DeviceDirectoryHandle
);