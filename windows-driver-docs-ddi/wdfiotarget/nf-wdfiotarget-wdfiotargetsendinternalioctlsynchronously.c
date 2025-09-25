NTSTATUS WdfIoTargetSendInternalIoctlSynchronously(
  [in]            WDFIOTARGET               IoTarget,
  [in, optional]  WDFREQUEST                Request,
  [in]            ULONG                     IoctlCode,
  [in, optional]  PWDF_MEMORY_DESCRIPTOR    InputBuffer,
  [in, optional]  PWDF_MEMORY_DESCRIPTOR    OutputBuffer,
  [in, optional]  PWDF_REQUEST_SEND_OPTIONS RequestOptions,
  [out, optional] PULONG_PTR                BytesReturned
);