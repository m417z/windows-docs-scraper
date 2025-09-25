# EVT_WDF_OBJECT_CONTEXT_CLEANUP callback function

## Description

[Applies to KMDF and UMDF]

A driver's *EvtCleanupCallback* event callback function removes the driver's references on an object so that the object can be deleted.

## Parameters

### `Object` [in]

A handle to a framework object.

## Remarks

The driver can specify an *EvtCleanupCallback* callback function in a [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure. This structure is used as input to all of the framework methods that create framework objects, such as [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate).

The framework calls the callback function when either the framework or a driver attempts to delete the object.

If the driver has called [WdfObjectReference](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfobjectreference) to increase the reference count of an object, the driver must provide an *EvtCleanupCallback* callback function that calls [WdfObjectDereference](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfobjectdereference). This call ensures that the object's reference count is decremented to zero and, as a result, the framework can call the driver's [EvtDestroyCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_destroy) callback function and then delete the object.

If a driver supplies both an *EvtCleanupCallback* callback function and an [EvtDestroyCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_destroy) callback function for an object, the framework calls the *EvtCleanupCallback* callback function first.

After the framework calls an object's *EvtCleanupCallback* callback function, the driver can access the object only from its [EvtDestroyCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_destroy) callback function. However, a driver should not attempt to call methods on an object from its EvtDestroyCallback.

When a driver creates an object, it sometimes allocates object-specific memory buffers and stores the buffer pointers in the object's [context space](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-context-space). The driver's *EvtCleanupCallback* or [EvtDestroyCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_destroy) callback function can deallocate these memory buffers.

Typically, if your driver does not call [WdfObjectReference](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfobjectreference) for an object, the object's *EvtCleanupCallback* callback function can deallocate object context allocations. In this case, the driver does not need an [EvtDestroyCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_destroy) callback function for the object.

When an object is deleted, the framework also deletes the object's children. With one exception, the framework calls the *EvtCleanupCallback* routines of child objects before calling those of their parent objects, so drivers are guaranteed that the parent object still exists when a child's *EvtCleanupCallback* routine runs.

The exception to this guaranteed ordering applies to I/O requests that the driver completes at DISPATCH_LEVEL. If such an I/O request object has one or more children whose *EvtCleanupCallback* routines must be called at PASSIVE_LEVEL, the parent request might be deleted before one or more of its children. An object requires cleanup at PASSIVE_LEVEL if it must wait for something to complete or if it accesses paged memory.

If the driver attempts to delete such an object (or the parent of such an object) while it is running at DISPATCH_LEVEL, the framework queues the *EvtCleanupCallback* to a work item for later processing at PASSIVE_LEVEL and then calls the cleanup callback for the parent object without determining whether the callbacks for the children have run.

To avoid any problems that might result from this behavior, drivers should not set the request object as the parent for any object that requires cleanup at PASSIVE_LEVEL. By default, the parent for most objects is WDFDEVICE, so drivers should just accept the default. Generally, if the WDFDEVICE object is passed as a parameter (either directly or as part of a structure) to the method that creates the object, the WDFDEVICE is the default parent. For a complete list of default parents, see [Summary of Framework Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/summary-of-framework-objects).

 If the above exception does not apply, the framework calls the child object's *EvtCleanupCallback* callback functions before calling the parent object's *EvtCleanupCallback* callback function. Next, if the child's reference count is zero, the framework calls the child object's [EvtDestroyCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_destroy) callback function. Finally, if the parent's reference count is zero, the framework calls the parent object's *EvtDestroyCallback* callback function.

For more information about deleting framework objects, see [Framework Object Life Cycle](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-life-cycle).

Typically, the framework calls the *EvtCleanupCallback* callback function at IRQL <= DISPATCH_LEVEL. However, the framework calls the callback function at IRQL = PASSIVE_LEVEL in the following situations:

* The object's handle type is WDFDEVICE, WDFDRIVER, WDFDPC, WDFINTERRUPT, WDFIOTARGET, WDFQUEUE, WDFSTRING, WDFTIMER, or WDFWORKITEM.
* The object's handle type is WDFMEMORY or WDFLOOKASIDE, and the driver has specified **PagedPool** for the *PoolType* parameter to [WdfMemoryCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorycreate) or [WdfLookasideListCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdflookasidelistcreate).

When a work-item object is deleted, either explicitly or because the work item's parent object is being deleted, then before calling the work item's *EvtCleanupCallback* callback function, the framework waits until all instances of the work item's [EvtWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfworkitem/nc-wdfworkitem-evt_wdf_workitem) callback function have returned. For more information, see [WdfWorkItemEnqueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfworkitem/nf-wdfworkitem-wdfworkitemenqueue).

Similarly, when a timer object is deleted, either explicitly or because the timer's parent object is being deleted, then before calling the timer's *EvtCleanupCallback* callback function, the framework waits until all instances of the timer's [EvtTimerFunc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftimer/nc-wdftimer-evt_wdf_timer) event callback function have returned.

Beginning with version 1.9 of the framework, the *wdfroletypes.h* header file contains some alternative, object type-specific, function types for the *EvtCleanupCallback* callback function. These alternative types help verification tools to determine whether the driver is properly using the callback function. Use the following table to determine which function type to use.

| Object Type | Function Type |
| --- | --- |
| Device object | EVT_WDF_DEVICE_CONTEXT_CLEANUP |
| I/O queue object | EVT_WDF_IO_QUEUE_CONTEXT_CLEANUP_CALLBACK |
| File object | EVT_WDF_FILE_CONTEXT_CLEANUP_CALLBACK |
| All other objects | EVT_WDF_OBJECT_CONTEXT_CLEANUP |

## See also

[EvtDestroyCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_destroy)

[WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes)

[WdfObjectDereference](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfobjectdereference)

[WdfObjectReference](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfobjectreference)

[WdfWorkItemFlush](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfworkitem/nf-wdfworkitem-wdfworkitemflush)