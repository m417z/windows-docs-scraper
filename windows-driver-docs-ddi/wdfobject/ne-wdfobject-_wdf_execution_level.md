# _WDF_EXECUTION_LEVEL enumeration

## Description

[Applies to KMDF and UMDF]

The WDF_EXECUTION_LEVEL enumeration type specifies the maximum IRQL at which the framework will call the event callback functions that a driver has supplied for a framework object.

## Constants

### `WdfExecutionLevelInvalid:0x00`

Reserved for system use.

### `WdfExecutionLevelInheritFromParent`

The framework uses the maximum IRQL value of the object's parent, unless the object is one that requires IRQL = DISPATCH_LEVEL (such as a DPC object). This value is the default if a driver does not specify a WDF_EXECUTION_LEVEL-typed value.

### `WdfExecutionLevelPassive`

The framework always calls the object's callback functions at IRQL = PASSIVE_LEVEL.

### `WdfExecutionLevelDispatch`

The framework calls the object's callback functions at IRQL <= DISPATCH_LEVEL. Not available in UMDF.

## Remarks

Drivers use the WDF_EXECUTION_LEVEL enumeration type to specify the **ExecutionLevel** member of an object's [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure.

You can specify an **ExecutionLevel** value for the following objects:

* Framework driver objects
* Framework device objects
* Framework file objects
* Framework general objects
* Framework queue objects (Framework versions 1.9 and later)
* Framework timer objects (Framework versions 1.9 and later)

**KMDF** By default, the framework sets the **ExecutionLevel** value of framework driver objects to **WdfExecutionLevelDispatch.**

**UMDF** By default, the framework sets the **ExecutionLevel** value of framework driver objects to **WdfExecutionLevelPassive.**

The default **ExecutionLevel** value for all other objects is **WdfExecutionLevelInheritFromParent.**

For more information about execution levels for event callback functions, see [Synchronization Techniques for Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/synchronization-techniques-for-wdf-drivers).

## See also

[WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes)