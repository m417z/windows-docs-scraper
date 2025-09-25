NTSTATUS IoGetDeviceObjectPointer(
  [in]  PUNICODE_STRING ObjectName,
  [in]  ACCESS_MASK     DesiredAccess,
  [out] PFILE_OBJECT    *FileObject,
  [out] PDEVICE_OBJECT  *DeviceObject
);