# EVT_UCX_ENDPOINT_SET_CHARACTERISTIC callback function

## Description

UCX invokes this callback function to set the priority on an endpoint.

## Parameters

### `UcxEndpoint` [in]

A handle to a UCXENDPOINT object that represents the endpoint.

### `UcxEndpointCharacteristic` [in]

A pointer to a [UCX_ENDPOINT_CHARACTERISTIC](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxendpoint/ns-ucxendpoint-_ucx_endpoint_characteristic) structure that contains endpoint characteristics.

## Remarks

The UCX client driver registers this callback function with the USB host controller extension (UCX) by calling the [UcxEndpointCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxendpoint/nf-ucxendpoint-ucxendpointcreate) method.

## See also

- [USB client drivers for Media-Agnostic (MA-USB)](https://learn.microsoft.com/windows-hardware/drivers/usbcon/usb-client-drivers-for-ma-usb)