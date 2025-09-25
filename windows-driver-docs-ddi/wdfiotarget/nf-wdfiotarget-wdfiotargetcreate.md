# WdfIoTargetCreate function

## Description

[Applies to KMDF and UMDF]

The **WdfIoTargetCreate** method creates a [remote I/O target](https://learn.microsoft.com/windows-hardware/drivers/wdf/general-i-o-targets) for a specified device.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `IoTargetAttributes` [in, optional]

A pointer to a caller-allocated [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that specifies object attributes for the I/O target object. This parameter is optional and can be WDF_NO_OBJECT_ATTRIBUTES.

### `IoTarget` [out]

A pointer to a location that receives a handle to an I/O target object.

## Return value

**WdfIoTargetCreate** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was detected. |
| **STATUS_INSUFFICIENT_RESOURCES** | There was insufficient memory to create a new I/O target object. |
| **STATUS_INVALID_DEVICE_REQUEST** | The **ParentObject** member of the [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that *IoTargetAttributes* specified did not specify the framework device object that *Device* specified, or an object whose chain of parents leads to that object. |

For a list of other return values that WdfIoTargetCreate can return, see [Framework Object Creation Errors](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-creation-errors).

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

After a driver calls **WdfIoTargetCreate**, the driver must call [WdfIoTargetOpen](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetopen) before it can send requests to the remote I/O target.

If the driver specifies a parent object in the [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure's **ParentObject** member, the parent object can be a framework device object or any object whose chain of parents leads to a framework device object. The framework will delete the I/O target object when it (or the driver) deletes the device object.

For more information about **WdfIoTargetCreate**, see [Initializing a General I/O Target](https://learn.microsoft.com/windows-hardware/drivers/wdf/initializing-a-general-i-o-target).

If your driver provides [EvtCleanupCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_cleanup) or [EvtDestroyCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_destroy) callback functions for the I/O target object, note that the framework calls these callback functions at IRQL = PASSIVE_LEVEL.

For more information about I/O targets, see [Using I/O Targets](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-i-o-targets).

#### Examples

For a code example that uses **WdfIoTargetCreate**, see [WdfIoTargetOpen](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetopen).

## See also

[WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes)

[WdfIoTargetOpen](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetopen)