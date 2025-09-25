NTSTATUS UdecxUsbDeviceInitAddStringDescriptor(
  [in, out] PUDECXUSBDEVICE_INIT UdecxUsbDeviceInit,
  [in]      PCUNICODE_STRING     String,
  [in]      UCHAR                DescriptorIndex,
  [in]      USHORT               LanguageId
);