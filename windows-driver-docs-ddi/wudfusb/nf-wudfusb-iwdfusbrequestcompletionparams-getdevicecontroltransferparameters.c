void GetDeviceControlTransferParameters(
  [out, optional] IWDFMemory           **ppMemory,
  [out, optional] ULONG                *pLengthTransferred,
  [out, optional] SIZE_T               *pOffset,
  [out, optional] PWINUSB_SETUP_PACKET pSetupPacket
);