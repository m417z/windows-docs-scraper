NTSTATUS UdecxUsbDeviceInitAddStringDescriptorRaw(
  [in, out] PUDECXUSBDEVICE_INIT UdecxUsbDeviceInit,
  [in]      PUCHAR               Descriptor,
  [in]      USHORT               DescriptorLength,
  [in]      UCHAR                DescriptorIndex,
  [in]      USHORT               LanguageId
);