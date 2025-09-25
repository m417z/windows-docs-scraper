NTSTATUS WdfRequestForwardToParentDeviceIoQueue(
  [in] WDFREQUEST                   Request,
  [in] WDFQUEUE                     ParentDeviceQueue,
  [in] PWDF_REQUEST_FORWARD_OPTIONS ForwardOptions
);