# UFX_PROPRIETARY_CHARGER_SET_PROPERTY callback function

## Description

The filter driver's implementation to set a configurable property on the charger.

## Parameters

### `Context` [in]

 A pointer to a driver-defined context.

### `Property` [in]

 A pointer to a **CONFIGURABLE_CHARGER_PROPERTY_HEADER** structure (defined in charging.h) that describes the configurable charger property to set.

## Return value

If the operation is successful, the callback function must return STATUS_SUCCESS, or another status value for which NT_SUCCESS(status) equals TRUE. Otherwise it must return a status value for which NT_SUCCESS(status) equals FALSE.

## Remarks

To support handling of proprietary chargers, the USB lower filter driver must publish support. During the publishing process, the driver also registers its implementation of this callback function. For more information, see [USB filter driver for supporting proprietary chargers](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/mt188012(v=vs.85)).

In this callback function, the driver sets the specified property value. For example, after the detection of a HVDCP charger, the driver sets the output voltages to the specified value.

## See also

[USB filter driver for supporting proprietary chargers](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/mt188012(v=vs.85))