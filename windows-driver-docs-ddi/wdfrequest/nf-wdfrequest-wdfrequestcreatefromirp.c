NTSTATUS WdfRequestCreateFromIrp(
  [in, optional] PWDF_OBJECT_ATTRIBUTES RequestAttributes,
  [in]           PIRP                   Irp,
  [in]           BOOLEAN                RequestFreesIrp,
  [out]          WDFREQUEST             *Request
);