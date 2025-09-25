NTSTATUS WdfUsbTargetPipeReadSynchronously(
  [in]            WDFUSBPIPE                Pipe,
  [in, optional]  WDFREQUEST                Request,
  [in, optional]  PWDF_REQUEST_SEND_OPTIONS RequestOptions,
  [in, optional]  PWDF_MEMORY_DESCRIPTOR    MemoryDescriptor,
  [out, optional] PULONG                    BytesRead
);