NTSTATUS USBD_QueryUsbCapability(
  [in]            USBD_HANDLE USBDHandle,
  [in]            const GUID  *CapabilityType,
  [in]            ULONG       OutputBufferLength,
  [in, out]       PUCHAR      OutputBuffer,
  [out, optional] PULONG      ResultLength
);