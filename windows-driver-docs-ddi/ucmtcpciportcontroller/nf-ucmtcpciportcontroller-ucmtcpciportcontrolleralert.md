# UcmTcpciPortControllerAlert function

## Description

Sends information about the hardware alerts that are received on the port controller to UcmTcpciCx.

## Parameters

### `PortControllerObject` [in]

Handle to the port controller object that the client driver received in the previous call to [UcmTcpciPortControllerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpciportcontroller/nf-ucmtcpciportcontroller-ucmtcpciportcontrollercreate).

### `AlertData`

A pointer to an array of [UCMTCPCI_PORT_CONTROLLER_ALERT_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpciportcontroller/ns-ucmtcpciportcontroller-_ucmtcpci_port_controller_alert_data) that contains all current alerts that have not been sent to UcmTcpciCx. This value cannot be NULL.

### `NumberOfAlerts`

The number of items in the array pointed to by *AlertData*. This value cannot be 0.

## Remarks

**UcmTcpciPortControllerAlert** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this inline function may return an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) error code.

The client driver must call **UcmTcpciPortControllerAlert** that has been previously started by calling [UcmTcpciPortControllerStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpciportcontroller/nf-ucmtcpciportcontroller-ucmtcpciportcontrollerstart).

When a hardware alert occurs, the client driver must determine the type of alerts, fetch any auxiliary information associated with that alert, such as a PD message, populate the array, and then call **UcmTcpciPortControllerAlert**.

The client driver must report the alerts sequentially. The driver must not call this method on threads that are running simultaneously as that can lead to race conditions. Even though the class extension ensures that all internal data is correctly lock-protected, if the driver calls **UcmTcpciPortControllerAlert** from multiple threads at the same time without any external synchronization, it is not guaranteed that set of received alerts is current. To avoid that scenario, the driver must call this method within the [Interrupt Service Routine](https://learn.microsoft.com/windows-hardware/drivers/kernel/interrupt-service-routines) (ISR)or a [DPC object](https://learn.microsoft.com/windows-hardware/drivers/kernel/dpc-objects-and-dpcs) that is queued for the ISR. The ISR should be synchronized correctly to have only one instance running at any given time.

The client driver must assume that the class extension may submit requests before **UcmTcpciPortControllerAlert** returns, from within this call.

When handling alerts, UcmTcpciCx may send hardware requests to the client driver before the **UcmTcpciPortControllerAlert** call returns. If the driver holds a lock while calling **UcmTcpciPortControllerAlert** and also attempts to acquire the same lock when handling the hardware request, deadlock can occur.

## See also

- [Handling Hardware Interrupts](https://learn.microsoft.com/windows-hardware/drivers/wdf/handling-hardware-interrupts)