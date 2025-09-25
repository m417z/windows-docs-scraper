# UcmTcpciPortControllerStart function

## Description

Indicates to the UcmTcpciCx class extension that the client driver is now ready to service hardware requests for the port controller.

## Parameters

### `PortControllerObject`

Handle to the port controller object that the client driver received in the previous call to [UcmTcpciPortControllerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpciportcontroller/nf-ucmtcpciportcontroller-ucmtcpciportcontrollercreate).

## Return value

(NTSTATUS) The method returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method may return an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) error code.

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_DEVICE_REQUEST** | The port controller is already in Start state. |
| **STATUS_INVALID_HANDLE** | Hardware request queue has not been set by calling [UcmTcpciPortControllerSetHardwareRequestQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpciportcontroller/nf-ucmtcpciportcontroller-ucmtcpciportcontrollersethardwarerequestqueue). |

## Remarks

After the client driver has received the UCMPORTCONTROLLER handle for the port controller object, the driver calls this method to notify the class extension that the driver can start receiving hardware requests. This method call allows the client driver to perform initialization of its framework context space on the port controller object, before the class extension can invoke the driver's callback functions or requests for the port controller object. The driver cannot call [UcmTcpciPortControllerAlert](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpciportcontroller/nf-ucmtcpciportcontroller-ucmtcpciportcontrolleralert) or [UcmTcpciPortControllerStop](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpciportcontroller/nf-ucmtcpciportcontroller-ucmtcpciportcontrollerstop) until the port controller has been started.

The client driver calls this method right after calling [UcmTcpciPortControllerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpciportcontroller/nf-ucmtcpciportcontroller-ucmtcpciportcontrollercreate) and initializing its context structure, if it was specified in the [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure as the *Attributes* parameter value.
The driver must assume that the class extension may submit requests even before **UcmTcpciPortControllerStart** returns, i.e., from within this DDI call. If the driver is holding a lock while calling **UcmTcpciPortControllerStart** and also attempts to acquire a lock while handling a hardware request (in its hardware request queue callback), it might result in a deadlock.

A call to **UcmTcpciPortControllerStart** to start a port controller object already in Start state, results in an error.

On boot, if the BIOS had already negotiated a PD contract, UcmTcpciCx starts from an unattached state.

## See also

[UcmTcpciPortControllerStop](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpciportcontroller/nf-ucmtcpciportcontroller-ucmtcpciportcontrollerstop)