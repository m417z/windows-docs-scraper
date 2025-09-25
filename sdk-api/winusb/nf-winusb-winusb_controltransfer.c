BOOL WinUsb_ControlTransfer(
  [in]            WINUSB_INTERFACE_HANDLE InterfaceHandle,
  [in]            WINUSB_SETUP_PACKET     SetupPacket,
  [out]           PUCHAR                  Buffer,
  [in]            ULONG                   BufferLength,
  [out, optional] PULONG                  LengthTransferred,
  [in, optional]  LPOVERLAPPED            Overlapped
);