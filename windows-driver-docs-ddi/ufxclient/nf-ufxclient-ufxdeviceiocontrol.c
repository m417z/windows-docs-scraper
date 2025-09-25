BOOLEAN UfxDeviceIoControl(
  [in] UFXDEVICE  UfxDevice,
  [in] WDFREQUEST Request,
  [in] size_t     OutputBufferLength,
  [in] size_t     InputBufferLength,
  [in] ULONG      IoControlCode
);