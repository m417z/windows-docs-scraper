NTSTATUS WdfRequestCreate(
  [in, optional] PWDF_OBJECT_ATTRIBUTES RequestAttributes,
  [in, optional] WDFIOTARGET            IoTarget,
  [out]          WDFREQUEST             *Request
);