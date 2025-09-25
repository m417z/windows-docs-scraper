# BOUND_CALLBACK callback function

## Description

The *BoundCallback* routine is executed whenever the system issues a bounds exception for a user-mode thread.

## Return value

A [BOUND_CALLBACK_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_bound_callback_status) value that indicates how the bounds exception was processed by the callback function.

## Remarks

Drivers can supply a *BoundCallback* that is called when the system issues a bounds exception.

Use [KeRegisterBoundCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keregisterboundcallback) to register a *BoundCallback* routine. A driver can subsequently remove the callback by using the [KeDeregisterBoundCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kederegisterboundcallback) routine. If the driver can be unloaded, it must remove any registered callbacks in its [Unload](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_unload) routine.

## See also

[KeDeregisterBoundCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kederegisterboundcallback)

[KeRegisterBoundCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keregisterboundcallback)