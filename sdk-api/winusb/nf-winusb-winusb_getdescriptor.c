BOOL WinUsb_GetDescriptor(
  [in]  WINUSB_INTERFACE_HANDLE InterfaceHandle,
  [in]  UCHAR                   DescriptorType,
  [in]  UCHAR                   Index,
  [in]  USHORT                  LanguageID,
  [out] PUCHAR                  Buffer,
  [in]  ULONG                   BufferLength,
  [out] PULONG                  LengthTransferred
);