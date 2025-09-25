# PFNKSDEVICEQUERYPOWER callback function

## Description

AVStream calls a minidriver's *AVStrMiniDeviceQueryPower* routine when it receives an [IRP_MN_QUERY_POWER](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-power) request.

## Parameters

### `Device` [in]

Pointer to the [KSDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice) structure that dispatched the [IRP_MN_QUERY_POWER](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-power).

### `Irp` [in]

Pointer to the [IRP_MN_QUERY_POWER](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-power) issued by *Device*.

### `DeviceTo` [in]

The power state requested by the issuer of *Irp*.

### `DeviceFrom` [in]

The current device power state.

### `SystemTo` [in]

System state to transition to, specified when a system power state transition is being queried. This value is unspecified if the call is due to a device power state change query.

### `SystemFrom` [in]

Current system state, specified when a system power state transition is being queried. This value is unspecified if the call is due to a device power state change query.

### `Action` [in]

Specifies additional information about the requested transition. Possible values are enumerators of the POWER_ACTION type.

## Return value

Should return STATUS_SUCCESS or the error code that was returned from the attempt to perform the operation. By returning STATUS_SUCCESS, the driver guarantees that it will not start any operation that would change its ability to set the requested power state. The driver should queue any IRP that would require such an operation until it completes a [IRP_MN_SET_POWER](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-set-power) that returns the device to an acceptable power state.

## Remarks

The power manager or a device power policy owner sends an [IRP_MN_QUERY_POWER](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-power) request to determine whether it can change the system or device power state (for example, to go to sleep).

If a driver fails an IRP_MN_QUERY_POWER request for a system power state, the power manager typically responds by issuing an [IRP_MN_SET_POWER](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-set-power). Usually, this IRP will reaffirm the current system state. However, it is possible that drivers might receive an IRP_MN_SET_POWER to the queried state or to some other intermediate state. Drivers should be prepared to handle these situations.

The minidriver specifies this routine's address in the **QueryPower** member of its [KSDEVICE_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice_dispatch) structure.

This routine is optional.

## See also

[IRP_MN_QUERY_POWER](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-power)

[KSDEVICE_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice_dispatch)