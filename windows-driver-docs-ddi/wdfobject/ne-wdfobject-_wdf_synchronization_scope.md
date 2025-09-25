# _WDF_SYNCHRONIZATION_SCOPE enumeration

## Description

[Applies to KMDF and UMDF]

The WDF_SYNCHRONIZATION_SCOPE enumeration type specifies how the framework will synchronize execution of an object's event callback functions.

## Constants

### `WdfSynchronizationScopeInvalid:0x00`

Reserved for system use.

### `WdfSynchronizationScopeInheritFromParent`

The framework uses the synchronization scope value that was specified for the object's parent object. This value is the default if a driver does not specify a WDF_SYNCHRONIZATION_SCOPE-typed value.

### `WdfSynchronizationScopeDevice`

The framework synchronizes execution of the event callback functions of all queue and file objects that are underneath a device object in the driver's object hierarchy.

Additionally, if the driver sets the **AutomaticSerialization** member to **TRUE** in the configuration structure for an interrupt, DPC, work-item, or timer object that is underneath the same device object, the framework also synchronizes that object's callback functions.

The framework obtains the device object's synchronization lock before calling a callback function. Therefore, these callback functions run one at a time. However, if the driver creates multiple objects of the same type, but under different device objects, their event callback functions might run concurrently on a multiprocessor system.

### `WdfSynchronizationScopeQueue`

This value affects queue objects only. The framework synchronizes the event callback functions of the queue object so that only one executes at a time.

Additionally, if the driver sets **AutomaticSerialization** to **TRUE** in the configuration structure for an interrupt, DPC, work-item, or timer object that is underneath the queue object or its parent device object, the framework also synchronizes that object's callback functions.

The framework obtains the queue object's synchronization lock before calling any callback functions that belong to the object.

If the driver creates multiple queue objects, their event callback functions might run concurrently on a multiprocessor system.

For framework versions 1.9 and later, a driver should set **WdfSynchronizationScopeQueue** for individual queue objects. To use this scope with earlier versions of the framework, the driver must set **WdfSynchronizationScopeQueue** for the parent device object and **WdfSynchronizationScopeInheritFromParent** for the queue object.

### `WdfSynchronizationScopeNone`

The framework does not synchronize the object's event callback functions, so the callback functions might run concurrently on a multiprocessor system.

## Remarks

Drivers use the WDF_SYNCHRONIZATION_SCOPE enumeration type to specify the **SynchronizationScope** member of an object's [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure.

You can specify a **SynchronizationScope** value for only the following objects:

* Framework driver objects
* Framework device objects
* Framework queue objects

The framework sets the **SynchronizationScope** value of framework driver objects to **WdfSynchronizationScopeNone**. It sets the **SynchronizationScope** value of framework device objects and framework queue objects to **WdfSynchronizationScopeInheritFromParent**.

For more information about synchronization of a driver's event callback functions, see [Synchronization Techniques for Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/synchronization-techniques-for-wdf-drivers).

## See also

[WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes)