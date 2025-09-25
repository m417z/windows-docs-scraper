# UdecxUrbRetrieveControlSetupPacket function

## Description

Retrieves a USB control setup packet from a specified framework request object.

## Parameters

### `Request` [in]

A handle to a framework request object that represents the request containing the setup packet.

### `SetupPacket` [out]

A [WDF_USB_CONTROL_SETUP_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_control_setup_packet) structure that receives a setup packet describing the USB control transfer.

## Return value

The method returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) error code.

## Remarks

The client driver can inspect contents of the setup packet to determine the standard control request that is sent to the device.

To complete the request, the driver must call [UdecxUrbCompleteWithNtStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxurb/nf-udecxurb-udecxurbcompletewithntstatus).

## See also

[Architecture: USB Device Emulation (UDE)](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)

[Write a UDE client driver](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)