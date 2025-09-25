# WdfWorkItemCreate function

## Description

[Applies to KMDF and UMDF]

The **WdfWorkItemCreate** method creates a framework work-item object, which can subsequently be added to the system's work-item queue.

## Parameters

### `Config` [in]

A pointer to a caller-allocated [WDF_WORKITEM_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfworkitem/ns-wdfworkitem-_wdf_workitem_config) structure that the driver must have already initialized by calling [WDF_WORKITEM_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfworkitem/nf-wdfworkitem-wdf_workitem_config_init).

### `Attributes` [in]

A pointer to a caller-allocated [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that specifies attributes for the work-item object.

### `WorkItem` [out]

A pointer to a variable that receives a handle to the new work-item object.

## Return value

**WdfWorkItemCreate** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was supplied. |
| **STATUS_INVALID_DEVICE_REQUEST** | The work-item object's parent is not a device object or the ancestor of a device object. |
| **STATUS_INSUFFICIENT_RESOURCES** | There were insufficient system resources to create a work-item object. |
| **STATUS_WDF_INCOMPATIBLE_EXECUTION_LEVEL** | The **AutomaticSerialization** member in the [WDF_WORKITEM_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfworkitem/ns-wdfworkitem-_wdf_workitem_config) structure that the *Config* parameter points to is **TRUE**, but the parent object's execution level is not **WdfExecutionLevelPassive**. |
| **STATUS_WDF_PARENT_NOT_SPECIFIED** | The *Attributes* parameter was **NULL**, or the **ParentObject** member of the [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that *Attributes* specifies was **NULL**. |

## Remarks

After a driver calls **WdfWorkItemCreate** to create a work item, it typically stores item-specific information in the context memory of the work-item object. The driver's [EvtWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfworkitem/nc-wdfworkitem-evt_wdf_workitem) callback function, which performs the work item's tasks, can access this information to determine the tasks that it must perform. (For more information about storing information in the context memory, see [Framework Object Context Space](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-context-space).)

After storing work-item information, the driver must call [WdfWorkItemEnqueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfworkitem/nf-wdfworkitem-wdfworkitemenqueue) to add the work item to the system's work-item queue. When a system worker thread becomes available, the thread removes the work item from the queue and calls the [EvtWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfworkitem/nc-wdfworkitem-evt_wdf_workitem) callback function.

When the driver creates a work-item object, it must specify a parent object for the work-item object in the **ParentObject** member of the [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure. The parent object must be a framework device object or any object whose chain of parents leads to a framework device object. The framework will delete the work-item object when it deletes the device object.

To delete the work-item object earlier, the driver can call [WdfObjectDelete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdfobjectdelete), as described in [Using Framework Work Items](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-framework-work-items).

The driver can retrieve a work item's parent object by calling [WdfWorkItemGetParentObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfworkitem/nf-wdfworkitem-wdfworkitemgetparentobject).

If your driver provides [EvtCleanupCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_cleanup) or [EvtDestroyCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_destroy) callback functions for the work-item object, note that the framework calls these callback functions at IRQL = PASSIVE_LEVEL.

For more information about work items, see [Using Framework Work Items](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-framework-work-items).

#### Examples

The following code example initializes a [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure, initializes a [WDF_WORKITEM_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfworkitem/ns-wdfworkitem-_wdf_workitem_config) structure, and calls **WdfWorkItemCreate**.

```cpp
NTSTATUS  status = STATUS_SUCCESS;
PWORKER_ITEM_CONTEXT  context;
WDF_OBJECT_ATTRIBUTES  attributes;
WDF_WORKITEM_CONFIG  workitemConfig;
WDFWORKITEM  hWorkItem;

WDF_OBJECT_ATTRIBUTES_INIT(&attributes);
WDF_OBJECT_ATTRIBUTES_SET_CONTEXT_TYPE(
                                       &attributes,
                                       WORKER_ITEM_CONTEXT
                                       );
attributes.ParentObject = FdoData->WdfDevice;

WDF_WORKITEM_CONFIG_INIT(
                         &workitemConfig,
                         CallbackFunction
                         );

status = WdfWorkItemCreate(
                            &workitemConfig,
                            &attributes,
                            &hWorkItem
                            );
if (!NT_SUCCESS(status)) {
    return status;
}
```

## See also

[WdfWorkItemEnqueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfworkitem/nf-wdfworkitem-wdfworkitemenqueue)