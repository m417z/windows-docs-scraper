BOOL WinUsb_RegisterIsochBuffer(
  [in]  WINUSB_INTERFACE_HANDLE     InterfaceHandle,
  [in]  UCHAR                       PipeID,
  [in]  PUCHAR                      Buffer,
  [in]  ULONG                       BufferLength,
  [out] PWINUSB_ISOCH_BUFFER_HANDLE IsochBufferHandle
);