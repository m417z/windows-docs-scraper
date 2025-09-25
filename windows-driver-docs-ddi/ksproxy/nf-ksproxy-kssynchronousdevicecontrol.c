KSDDKAPI HRESULT KsSynchronousDeviceControl(
  [in]            HANDLE Handle,
  [in]            ULONG  IoControl,
  [in, optional]  PVOID  InBuffer,
  [in]            ULONG  InLength,
  [out, optional] PVOID  OutBuffer,
  [in]            ULONG  OutLength,
  [in, out]       PULONG BytesReturned
);