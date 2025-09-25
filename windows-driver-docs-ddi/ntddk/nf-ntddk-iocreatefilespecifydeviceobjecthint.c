NTSTATUS IoCreateFileSpecifyDeviceObjectHint(
  [out]          PHANDLE            FileHandle,
  [in]           ACCESS_MASK        DesiredAccess,
  [in]           POBJECT_ATTRIBUTES ObjectAttributes,
  [out]          PIO_STATUS_BLOCK   IoStatusBlock,
  [in, optional] PLARGE_INTEGER     AllocationSize,
  [in]           ULONG              FileAttributes,
  [in]           ULONG              ShareAccess,
  [in]           ULONG              Disposition,
  [in]           ULONG              CreateOptions,
  [in, optional] PVOID              EaBuffer,
  [in]           ULONG              EaLength,
  [in]           CREATE_FILE_TYPE   CreateFileType,
  [in, optional] PVOID              InternalParameters,
  [in]           ULONG              Options,
  [in, optional] PVOID              DeviceObject
);