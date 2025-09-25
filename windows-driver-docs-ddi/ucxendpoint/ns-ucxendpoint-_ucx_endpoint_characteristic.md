# _UCX_ENDPOINT_CHARACTERISTIC structure

## Description

Stores the characteristics of an endpoint.

## Members

### `Size`

Size of this structure.

### `CharacteristicType`

A [UCX_ENDPOINT_CHARACTERISTIC_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxendpoint/ne-ucxendpoint-_ucx_endpoint_characteristic_type)-type value that indicates the type of endpoint characteristic.

### `Priority`

A [UCX_CONTROLLER_ENDPOINT_CHARACTERISTIC_PRIORITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxendpoint/ne-ucxendpoint-_ucx_endpoint_characteristic_priority)-typed value that indicates the priority of the endpoint.

## See also

[EVT_UCX_ENDPOINT_SET_CHARACTERISTIC](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxendpoint/nc-ucxendpoint-evt_ucx_endpoint_set_characteristic)

[UCX_CONTROLLER_ENDPOINT_CHARACTERISTIC_PRIORITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxendpoint/ne-ucxendpoint-_ucx_endpoint_characteristic_priority)