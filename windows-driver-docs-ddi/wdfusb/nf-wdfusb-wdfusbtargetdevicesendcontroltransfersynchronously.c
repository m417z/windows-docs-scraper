NTSTATUS WdfUsbTargetDeviceSendControlTransferSynchronously(
  [in]            WDFUSBDEVICE                  UsbDevice,
  [in, optional]  WDFREQUEST                    Request,
  [in, optional]  PWDF_REQUEST_SEND_OPTIONS     RequestOptions,
  [in]            PWDF_USB_CONTROL_SETUP_PACKET SetupPacket,
  [in, optional]  PWDF_MEMORY_DESCRIPTOR        MemoryDescriptor,
  [out, optional] PULONG                        BytesTransferred
);