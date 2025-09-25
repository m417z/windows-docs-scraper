VOID PosCxCleanPendingRequests(
  [in]           WDFDEVICE     device,
  [in, optional] WDFFILEOBJECT callerFileObj,
  [in]           NTSTATUS      completionStatus
);