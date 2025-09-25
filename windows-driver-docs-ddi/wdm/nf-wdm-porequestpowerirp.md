# PoRequestPowerIrp function

## Description

The **PoRequestPowerIrp** routine allocates a power [IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp) and sends it to the top driver in the device stack for the specified device.

## Parameters

### `DeviceObject` [in]

A pointer to the target [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) for the IRP. In Windows 2000 and later versions of Windows, this parameter can point to a physical device object ([PDO](https://learn.microsoft.com/windows-hardware/drivers/)) or a functional device object ([FDO](https://learn.microsoft.com/windows-hardware/drivers/)). In Windows 98/Me, this parameter must point to the PDO of the underlying device.

### `MinorFunction` [in]

Specifies one of the following minor power IRP codes: [IRP_MN_QUERY_POWER](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-power), [IRP_MN_SET_POWER](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-set-power), or [IRP_MN_WAIT_WAKE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-wait-wake).

### `PowerState` [in]

Specifies a [POWER_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_power_state) value to pass in the IRP. For **IRP_MN_SET_POWER** and **IRP_MN_QUERY_POWER**, specify the requested new [device power state](https://learn.microsoft.com/windows-hardware/drivers/kernel/device-power-states). Possible values are [DEVICE_POWER_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/ne-wudfddi-_device_power_state) values.

For **IRP_MN_WAIT_WAKE**, specify the lowest (least-powered) [system power state](https://learn.microsoft.com/windows-hardware/drivers/kernel/system-power-states) from which the device should be allowed to wake the system. Possible values are [SYSTEM_POWER_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_system_power_state) values.

### `CompletionFunction` [in, optional]

A pointer to the caller's [PowerCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-request_power_complete) callback routine. The I/O manager calls this routine when the IRP has completed. This parameter is optional and can be set to **NULL** if no *PowerCompletion* callback routine is needed.

### `Context` [in, optional]

A pointer to a caller-supplied context to be passed through to the *PowerCompletion* callback. When the caller requests a device set-power IRP in response to a system set-power IRP, *Context* should contain the system set-power IRP that triggered the request.

### `Irp` [out]

A pointer to a caller-supplied variable in which **PoRequestPowerIrp** returns a pointer to the IRP that it allocates. Specify a value for *Irp* only if the *MinorFunction* parameter is set to **IRP_MN_WAIT_WAKE**. Otherwise, this parameter should always be **NULL** because the IRP might be completed before **PoRequestPowerIrp** returns, causing this parameter to point to memory that has already been discarded.

## Return value

**PoRequestPowerIrp** returns one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_PENDING** | The IRP has been sent. |
| **STATUS_INSUFFICIENT_RESOURCES** | The routine could not allocate the IRP. |
| **STATUS_INVALID_PARAMETER_2** | *MinorFunction* does not signify a valid minor power IRP code. |

## Remarks

A device power policy owner calls this routine to send a wait/wake, query, or set-power IRP.

A driver calls **PoRequestPowerIrp**—not [IoAllocateIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioallocateirp)—to allocate and send a power IRP that has minor IRP code **IRP_MN_SET_POWER**, **IRP_MN_QUERY_POWER**, or **IRP_MN_WAIT_WAKE**. (A driver must call **IoAllocateIrp** to send a power IRP with minor IRP code [IRP_MN_POWER_SEQUENCE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-power-sequence).)

If **PoRequestPowerIrp** returns a status value of STATUS_PENDING, the routine successfully allocated a device power IRP and sent it to the top of the device stack for the device. After the bus driver and all other drivers have completed the IRP, and the I/O manager has called all [IoCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_completion_routine) routines set by drivers as they passed the IRP down the device stack, the I/O manager calls the [PowerCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-request_power_complete) routine and passes to this routine the specified *Context* value. If **PoRequestPowerIrp** returns a status other than STATUS_PENDING, the routine did not send a device power IRP and the *PowerCompletion* routine is not called.

The *PowerCompletion* routine performs any additional tasks the sender of the IRP requires after all other drivers have completed the IRP. It need not free the IRP; the power manager does that. In Windows 2000 and later versions of Windows, the *PowerCompletion* routine can be called at IRQL = PASSIVE_LEVEL or IRQL = DISPATCH_LEVEL. In Windows 98/Me, the *PowerCompletion* routine is always called at IRQL = PASSIVE_LEVEL, and drivers must complete IRPs at IRQL = PASSIVE_LEVEL.

A device power policy owner calls **PoRequestPowerIrp** to send a device query- or set-power IRP when it receives a system query- or set-power IRP. The driver should set an *IoCompletion* routine in the system IRP and pass the system IRP to the next lower driver. The *IoCompletion* routine calls **PoRequestPowerIrp** to send the device IRP, passing the system IRP in the *Context* parameter. The *Context* parameter is subsequently passed to the *PowerCompletion* routine for the device IRP. In the *PowerCompletion* routine, the driver can complete the system IRP. For more information, see [Sending IRP_MN_QUERY_POWER or IRP_MN_SET_POWER for Device Power States](https://learn.microsoft.com/windows-hardware/drivers/kernel/sending-irp-mn-query-power-or-irp-mn-set-power-for-device-power-states) and [Wait/Wake Callback Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/wait-wake-callback-routines).

Drivers can use the returned *Irp* to cancel an **IRP_MN_WAIT_WAKE** IRP. Drivers that are requesting other types of power IRPs must pass **NULL** for this parameter.

## See also

[IO_STATUS_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_status_block)

[IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp)

[IRP_MN_POWER_SEQUENCE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-power-sequence)

[IRP_MN_QUERY_POWER](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-power)

[IRP_MN_SET_POWER](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-set-power)

[IRP_MN_WAIT_WAKE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-wait-wake)

[IoAllocateIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioallocateirp)

[PoStartNextPowerIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-postartnextpowerirp)

[PowerCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-request_power_complete)