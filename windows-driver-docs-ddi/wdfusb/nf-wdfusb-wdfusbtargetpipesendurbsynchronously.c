NTSTATUS WdfUsbTargetPipeSendUrbSynchronously(
  [in]           WDFUSBPIPE                Pipe,
  [in, optional] WDFREQUEST                Request,
  [in, optional] PWDF_REQUEST_SEND_OPTIONS RequestOptions,
  [in]           PURB                      Urb
);