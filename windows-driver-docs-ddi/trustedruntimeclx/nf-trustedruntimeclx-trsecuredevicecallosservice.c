NTSTATUS TrSecureDeviceCallOSService(
  WDFDEVICE           Device,
  LPCGUID             OSServiceGuid,
  PTR_SERVICE_REQUEST CallData,
  ULONG_PTR           *BytesWritten
);