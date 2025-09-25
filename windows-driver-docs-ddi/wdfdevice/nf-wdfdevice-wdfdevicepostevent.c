NTSTATUS WdfDevicePostEvent(
  [in] WDFDEVICE      Device,
  [in] REFGUID        EventGuid,
  [in] WDF_EVENT_TYPE WdfEventType,
  [in] BYTE           *Data,
  [in] ULONG          DataSizeCb
);