NTSTATUS WdfIoQueueRetrieveRequestByFileObject(
  [in]  WDFQUEUE      Queue,
  [in]  WDFFILEOBJECT FileObject,
  [out] WDFREQUEST    *OutRequest
);