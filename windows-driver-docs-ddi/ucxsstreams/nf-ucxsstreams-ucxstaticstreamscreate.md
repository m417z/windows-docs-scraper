# UcxStaticStreamsCreate function

## Description

Creates a static streams object.

## Parameters

### `Endpoint` [in]

A handle to the endpoint object that supports static streams. The client driver retrieved the handle in a previous call to [UcxEndpointCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxendpoint/nf-ucxendpoint-ucxendpointcreate).

### `StaticStreamsInit`

A pointer to a **UCXSSTREAMS_INIT** structure that describes various configuration
operations for creating the stream object. The driver specifies function pointers to its callback functions in this structure.
This structure is managed by UCX.

### `Attributes` [in, optional]

A pointer to a caller-allocated [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that specifies attributes for the stream object.

### `StaticStreams`

A pointer to a variable that receives a handle to the new stream object.

## Return value

The method returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return one an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) error code.

## Remarks

The client driver for the host controller must call this method after the [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate) call. The parent of the new endpoint object is the endpoint object.

Typically, the client driver calls this method in its implementation of the [EVT_UCX_USBDEVICE_ENDPOINT_ADD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/nc-ucxusbdevice-evt_ucx_usbdevice_endpoint_add) event callback.