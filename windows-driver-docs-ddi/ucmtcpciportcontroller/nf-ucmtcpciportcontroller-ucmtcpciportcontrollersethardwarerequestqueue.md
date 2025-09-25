# UcmTcpciPortControllerSetHardwareRequestQueue function

## Description

 Assigns a framework queue object to which the UcmTcpciCx dispatches hardware requests for the port controller.

## Parameters

### `PortControllerObject`

Handle to the port controller object that the client driver received in the previous call to [UcmTcpciPortControllerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpciportcontroller/nf-ucmtcpciportcontroller-ucmtcpciportcontrollercreate).

### `HardwareRequestQueue`

A handle to the framework queue object to assign.

## Remarks

The client driver must call **UcmTcpciPortControllerSetHardwareRequestQueue** after creating the port controller object. The driver must call this method only once before calling [UcmTcpciPortControllerStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpciportcontroller/nf-ucmtcpciportcontroller-ucmtcpciportcontrollerstart).

The parent of the queue object is the port controller object.

A client driver may choose to use the same queue across multiple port controller objects. However, in that case the driver must make sure that the port controller objects do not outlive the queue object. The queue object must be deleted only after all the port controllers have been stopped. UcmTcpciCx guarantees that only one request is processed in the queue at a time per port controller object.

## See also

[UcmTcpciPortControllerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpciportcontroller/nf-ucmtcpciportcontroller-ucmtcpciportcontrollercreate)