NTSTATUS WdfIoQueueFindRequest(
  [in]           WDFQUEUE                Queue,
  [in, optional] WDFREQUEST              FoundRequest,
  [in, optional] WDFFILEOBJECT           FileObject,
  [in, out]      PWDF_REQUEST_PARAMETERS Parameters,
  [out]          WDFREQUEST              *OutRequest
);