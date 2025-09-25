# EVT_UCX_CONTROLLER_GET_TRANSPORT_CHARACTERISTICS callback function

## Description

 UCX invokes this callback to retrieve the host controller characteristics.

## Parameters

### `UcxController` [in]

 A handle to the UCX controller that the client driver received in a previous call to the [UcxControllerCreate](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/mt188033(v=vs.85)) method.

### `UcxControllerTransportCharacteristics` [out]

A pointer to a [UCX_CONTROLLER_TRANSPORT_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxcontroller/ns-ucxcontroller-_ucx_controller_transport_characteristics) structure that the client driver for the host controller fills with transport characteristics.

## Return value

If the operation is successful, the callback function must return STATUS_SUCCESS, or another status value for which NT_SUCCESS(status) equals TRUE. Otherwise it must return a status value for which NT_SUCCESS(status) equals FALSE.

## Remarks

The UCX client driver registers its implementation with the USB host controller extension (UCX) by calling the [UcxControllerCreate](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/mt188033(v=vs.85)) method.

This callback function is optional. Whenever transport characteristics change, the client driver is responsible for notifying UCX that one of the characteristics have changed using a new function [UcxControllerNotifyTransportCharacteristicsChange](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxcontroller/nf-ucxcontroller-ucxcontrollernotifytransportcharacteristicschange).

## See also

[UcxControllerCreate](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/mt188033(v=vs.85))