NTSTATUS WdfIoTargetSendInternalIoctlOthersSynchronously(
  [in]            WDFIOTARGET               IoTarget,
  [in, optional]  WDFREQUEST                Request,
  [in]            ULONG                     IoctlCode,
  [in, optional]  PWDF_MEMORY_DESCRIPTOR    OtherArg1,
  [in, optional]  PWDF_MEMORY_DESCRIPTOR    OtherArg2,
  [in, optional]  PWDF_MEMORY_DESCRIPTOR    OtherArg4,
  [in, optional]  PWDF_REQUEST_SEND_OPTIONS RequestOptions,
  [out, optional] PULONG_PTR                BytesReturned
);