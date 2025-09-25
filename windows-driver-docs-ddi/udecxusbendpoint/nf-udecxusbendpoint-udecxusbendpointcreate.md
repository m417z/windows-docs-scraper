# UdecxUsbEndpointCreate function

## Description

Creates a UDE endpoint object.

## Parameters

### `EndpointInit`

A pointer to an **UDECXUSBENDPOINT_INIT** structure that the client driver retrieved in the previous call to [**UdecxUsbSimpleEndpointInitAllocate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbendpoint/nf-udecxusbendpoint-udecxusbsimpleendpointinitallocate).

### `Attributes` [in, optional]

A pointer to a caller-allocated [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that specifies attributes for the USB device object.

### `UdecxUsbEndpoint` [out]

A pointer to a variable that receives a handle to the new UDE endpoint object that represents the simple endpoint on the USB device.

## Return value

The method returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) error code.

## See also

[Architecture: USB Device Emulation (UDE)](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)

[UdecxUsbSimpleEndpointInitAllocate](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbendpoint/nf-udecxusbendpoint-udecxusbsimpleendpointinitallocate)

[Write a UDE client driver](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)