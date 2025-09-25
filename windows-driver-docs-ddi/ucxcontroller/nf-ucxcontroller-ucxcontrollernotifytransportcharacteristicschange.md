# UcxControllerNotifyTransportCharacteristicsChange function

## Description

Notifies UCX about a new port change event from host controller.

## Parameters

### `Controller`

A handle to the UCX controller that the client driver received in a previous call to the [**UcxControllerCreate**](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/mt188033(v=vs.85)) method.

### `UcxControllerTransportCharacteristics` [out]

A pointer to a [UCX_CONTROLLER_TRANSPORT_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxcontroller/ns-ucxcontroller-_ucx_controller_transport_characteristics) structure that contains the updated transport characteristics.

## See also

[EVT_UCX_CONTROLLER_GET_TRANSPORT_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxcontroller/nc-ucxcontroller-evt_ucx_controller_get_transport_characteristics)