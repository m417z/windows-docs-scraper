# WdfWorkItemGetParentObject function

## Description

[Applies to KMDF and UMDF]

The **WdfWorkItemGetParentObject** method returns the framework object that a specified work item is associated with.

## Parameters

### `WorkItem` [in]

A handle to a framework work-item object that is obtained from a previous call to [WdfWorkItemCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfworkitem/nf-wdfworkitem-wdfworkitemcreate).

## Return value

**WdfWorkItemGetParentObject** returns a handle to the framework object that the driver specified as the **ParentObject** member of the driver's [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure when the driver previously called [WdfWorkItemCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfworkitem/nf-wdfworkitem-wdfworkitemcreate).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

For more information about work items, see [Using Framework Work Items](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-framework-work-items).

#### Examples

The following code example is an [EvtWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfworkitem/nc-wdfworkitem-evt_wdf_workitem) callback function from the [1394](https://learn.microsoft.com/windows-hardware/drivers/wdf/sample-kmdf-drivers) sample driver. The example obtains a work item's parent device object, calls a driver-defined routine to process the work item, and then deletes the work item object.

```cpp
VOID
t1394_BusResetRoutineWorkItem(
    IN WDFWORKITEM  WorkItem
)
{
    WDFDEVICE  Device = WdfWorkItemGetParentObject(WorkItem);

    t1394_UpdateGenerationCount(Device);

    WdfObjectDelete(WorkItem);
}
```

## See also

[WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes)

[WdfWorkItemCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfworkitem/nf-wdfworkitem-wdfworkitemcreate)