NTSTATUS WdfIoTargetSendWriteSynchronously(
  [in]            WDFIOTARGET               IoTarget,
  [in, optional]  WDFREQUEST                Request,
  [in, optional]  PWDF_MEMORY_DESCRIPTOR    InputBuffer,
  [in, optional]  PLONGLONG                 DeviceOffset,
  [in, optional]  PWDF_REQUEST_SEND_OPTIONS RequestOptions,
  [out, optional] PULONG_PTR                BytesWritten
);