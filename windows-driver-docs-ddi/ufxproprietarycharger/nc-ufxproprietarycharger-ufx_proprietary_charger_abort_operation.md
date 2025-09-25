# UFX_PROPRIETARY_CHARGER_ABORT_OPERATION callback function

## Description

The filter driver's implementation to abort a charger operation.

## Parameters

### `Context` [in]

 A pointer to a driver-defined context.

## Return value

If the operation is successful, the callback function must return STATUS_SUCCESS, or another status value for which NT_SUCCESS(status) equals TRUE. Otherwise it must return a status value for which NT_SUCCESS(status) equals FALSE.

## Remarks

To support handling of proprietary chargers, the USB lower filter driver must publish support. During the publishing process, the driver also registers its implementation of this callback function. For more information, see [USB filter driver for supporting proprietary chargers](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/mt188012(v=vs.85)).

## See also

[USB filter driver for supporting proprietary chargers](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/mt188012(v=vs.85))