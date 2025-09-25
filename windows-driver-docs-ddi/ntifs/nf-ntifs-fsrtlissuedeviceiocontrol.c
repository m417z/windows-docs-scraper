NTSTATUS FsRtlIssueDeviceIoControl(
  [in]            PDEVICE_OBJECT DeviceObject,
  [in]            ULONG          IoCtl,
                  UCHAR          Flags,
  [in, optional]  PVOID          InputBuffer,
  [in]            ULONG          InputBufferLength,
  [out, optional] PVOID          OutputBuffer,
  [in]            ULONG          OutputBufferLength,
  [in]            PULONG_PTR     IosbInformation
);