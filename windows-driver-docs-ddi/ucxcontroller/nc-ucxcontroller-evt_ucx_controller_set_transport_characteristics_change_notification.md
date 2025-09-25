# EVT_UCX_CONTROLLER_SET_TRANSPORT_CHARACTERISTICS_CHANGE_NOTIFICATION callback function

## Description

UCX invokes this callback function to specify its preference in transport characteristics for which the client driver must send notifications when changes occur.

## Parameters

### `UcxController` [in]

 A handle to the UCX controller that the client driver received in a previous call to the [UcxControllerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxcontroller/nf-ucxcontroller-ucxcontrollercreate) method.

### `ChangeNotificationFlags` [in]

A bitwise option of flags that indicate the type transport characteristics in which UCX is interested. The flags are defined in [UCX_CONTROLLER_TRANSPORT_CHARACTERISTICS_CHANGE_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxcontroller/ns-ucxcontroller-_ucx_controller_transport_characteristics_change_flags).

## Remarks

If the operation is successful, the callback function must return STATUS_SUCCESS, or another status value for which NT_SUCCESS(status) equals TRUE. Otherwise it must return a status value for which NT_SUCCESS(status) equals FALSE.

The UCX client driver registers its implementation with the USB host controller extension (UCX) by calling the [UcxControllerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxcontroller/nf-ucxcontroller-ucxcontrollercreate) method.

For efficient power consumption, UCX invokes this callback function to specify the transport characteristics in which UCX is interested.

It is likely that if the client driver keeps looking for changes in transport characteristics in the controller. This may result in a high power consumption and may be inefficient if there are no USB device drivers registered for that change notification. To optimize the power consumption, UCX invokes this callback function to let the client driver know if any clients are registered for changes. This callback function passes the change notification flags as parameter. If a flag is set, it indicates that there is at least one device driver registered. If the flag is not set, it means that there are no clients registered and hence the controller can optimize power.

> [!NOTE]
> It is optional for controller drivers to register or make use of these callback functions. It is valid for a controller driver to invoke the change notification even if UCX has indicated that there are no clients registered for it.

## See also

- [UcxControllerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxcontroller/nf-ucxcontroller-ucxcontrollercreate)