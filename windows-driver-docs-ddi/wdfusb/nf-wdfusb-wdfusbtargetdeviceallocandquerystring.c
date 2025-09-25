NTSTATUS WdfUsbTargetDeviceAllocAndQueryString(
  [in]            WDFUSBDEVICE           UsbDevice,
  [in, optional]  PWDF_OBJECT_ATTRIBUTES StringMemoryAttributes,
  [out]           WDFMEMORY              *StringMemory,
  [out, optional] PUSHORT                NumCharacters,
  [in]            UCHAR                  StringIndex,
  [in, optional]  USHORT                 LangID
);