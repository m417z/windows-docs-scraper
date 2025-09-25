# UcmTcpciPortControllerStop function

## Description

Indicates to the UcmTcpciCx class extension to stop sending hardware requests to the port controller object.

## Parameters

### `PortControllerObject`

Handle to the port controller object that the client driver received in the previous call to [UcmTcpciPortControllerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpciportcontroller/nf-ucmtcpciportcontroller-ucmtcpciportcontrollercreate).

## Remarks

After calling **UcmTcpciPortControllerStop**, the client driver stops processing all requests on the port controller object. This call is synchronous, so it is guaranteed that the class extension will not invoke callback functions or send requests after it returns. The driver must not call this method within a port controller callback, or while any non-cancelable hardware requests are pending.

A client driver calls this method from its [EVT_WDF_DEVICE_RELEASE_HARDWARE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_release_hardware) callback implementation. After doing so, it should also call [WdfObjectDelete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdfobjectdelete), in case *EVT_WDF_DEVICE_RELEASE_HARDWARE* is invoked to resource rebalancing. Failure to do so causes the driver to leak objects associated with the port controller object when a resource rebalance occurs. Parenting the UCMPORTCONTROLLER handle to the WDFDEVICE handle is not sufficient, because a WDFDEVICE is not deleted across a resource rebalance.

If the driver is transitioning to a Dx state due to S0-Idle, the driver must not call this method from its [EVT_WDF_DEVICE_D0_EXIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_d0_exit) callback function. Synchronization with the driver's power state can be achieved by using a power-managed queue to receive hardware requests.

It is safe to call **UcmTcpciPortControllerStop** on a port controller that has already been stopped. After this method returns, no other method except for [UcmTcpciPortControllerStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpciportcontroller/nf-ucmtcpciportcontroller-ucmtcpciportcontrollerstart) can be called on the port controller.

The client driver must call this method if it needs to stop all actions on the port controller so that it can perform error recovery if it detected any issues during its operation. After the recovery process has been completed, the driver must restart the port controller.

Stopping the controller ends any active PD contract and the Type-C connection.

## See also

[UcmTcpciPortControllerStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpciportcontroller/nf-ucmtcpciportcontroller-ucmtcpciportcontrollerstart)