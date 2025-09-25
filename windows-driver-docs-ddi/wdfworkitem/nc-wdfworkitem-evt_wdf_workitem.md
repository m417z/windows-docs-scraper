# EVT_WDF_WORKITEM callback function

## Description

[Applies to KMDF and UMDF]

A driver's *EvtWorkItem* event callback function performs the work that is associated with a specified work item.

## Parameters

### `WorkItem` [in]

A handle to a framework work-item object.

## Remarks

Typically, a driver's *EvtWorkItem* callback function performs tasks that are specified by information that the driver stored in the context memory of a work-item object.

To register an *EvtWorkItem* callback function, the driver calls [WdfWorkItemCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfworkitem/nf-wdfworkitem-wdfworkitemcreate).

After the *EvtWorkItem* callback function has performed the specified tasks, it must call [WdfObjectDelete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdfobjectdelete), unless the driver reuses work items.

For more information about work items, see [Using Framework Work Items](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-framework-work-items).

The *EvtWorkItem* callback function runs at IRQL = PASSIVE_LEVEL in the context of a system worker thread.

## See also

[WdfObjectDelete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdfobjectdelete)

[WdfWorkItemCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfworkitem/nf-wdfworkitem-wdfworkitemcreate)

[WdfWorkItemEnqueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfworkitem/nf-wdfworkitem-wdfworkitemenqueue)