# UcxEndpointCreate function

## Description

Creates an endpoint on the specified USB device object.

## Parameters

### `UsbDevice` [in]

A handle to the USB device object that contains the endpoint. The client driver retrieved the handle in a previous call to [UcxUsbDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/nf-ucxusbdevice-ucxusbdevicecreate).

### `EndpointInit` [out]

A pointer to a **UCXENDPOINT_INIT** structure that describes various configuration
operations for creating the endpoint object. The driver specifies function pointers to its callback functions in this structure.
This structure is managed by UCX.

### `Attributes` [in, optional]

A pointer to a caller-allocated [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that specifies attributes for the endpoint object.

### `Endpoint` [out]

A pointer to a variable that receives a handle to the new endpoint object.

## Return value

The method returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return one an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) error code.

## Remarks

The client driver for the host controller must call this method after the [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate) call. The parent of the new endpoint object is the USB device object.

The method initializes the endpoint object with information such as the type of endpoint, pipe, transfer, and maximum transfers size.

For a code example, see [EVT_UCX_USBDEVICE_ENDPOINT_ADD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/nc-ucxusbdevice-evt_ucx_usbdevice_endpoint_add).