NTSTATUS WdfRequestMarkCancelableEx(
  [in] WDFREQUEST             Request,
  [in] PFN_WDF_REQUEST_CANCEL EvtRequestCancel
);