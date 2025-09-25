NTSTATUS WdfUsbTargetDeviceFormatRequestForControlTransfer(
  [in]           WDFUSBDEVICE                  UsbDevice,
  [in]           WDFREQUEST                    Request,
  [in]           PWDF_USB_CONTROL_SETUP_PACKET SetupPacket,
  [in, optional] WDFMEMORY                     TransferMemory,
  [in, optional] PWDFMEMORY_OFFSET             TransferOffset
);