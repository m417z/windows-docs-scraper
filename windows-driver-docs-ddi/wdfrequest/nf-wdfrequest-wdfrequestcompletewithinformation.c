VOID WdfRequestCompleteWithInformation(
  [in] WDFREQUEST Request,
  [in] NTSTATUS   Status,
  [in] ULONG_PTR  Information
);