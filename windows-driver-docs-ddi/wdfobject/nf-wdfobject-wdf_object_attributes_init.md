# WDF_OBJECT_ATTRIBUTES_INIT function

## Description

[Applies to KMDF and UMDF]

The WDF_OBJECT_ATTRIBUTES_INIT function initializes a driver's [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure.

## Parameters

### `Attributes` [out]

A pointer to the driver's [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure.

## Remarks

The WDF_OBJECT_ATTRIBUTES_INIT function sets the **ExecutionLevel** member of the specified [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure to **WdfExecutionLevelInheritFromParent**, and it sets the **SynchronizationScope** member to **WdfSynchronizationScopeInheritFromParent**.

For code examples that use WDF_OBJECT_ATTRIBUTES_INIT, see [WdfObjectCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdfobjectcreate) and [WdfObjectGetTypedContext](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfobjectgettypedcontext).

## See also

[WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes)