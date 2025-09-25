# EVT_WDF_OBJECT_CONTEXT_DESTROY callback function

## Description

[Applies to KMDF and UMDF]

A driver's *EvtDestroyCallback* event callback function performs operations that are associated with the deletion of a framework object.

## Parameters

### `Object` [in]

A handle to a framework object.

## Remarks

The driver can specify an *EvtDestroyCallback* callback function in a [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure. This structure is used as input to all of the framework methods that create framework objects, such as [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate).

The framework calls the *EvtDestroyCallback* callback function after the object's reference count has been decremented to zero. The framework deletes the object immediately after the *EvtDestroyCallback* callback function returns.

The *EvtDestroyCallback* can access the object context but cannot call any methods on the object.

If a driver supplies both an [EvtCleanupCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_cleanup) callback function and an *EvtDestroyCallback* callback function for an object, the framework calls the *EvtCleanupCallback* callback function first.

When an object is deleted, the framework also deletes the object's children. The framework calls the child objects' [EvtCleanupCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_cleanup) callback functions before calling the parent object's *EvtCleanupCallback* callback function. Next, if the child's reference count is zero, the framework calls the child object's *EvtDestroyCallback* callback function. Finally, if the parent's reference count is zero, the framework calls the parent object's *EvtDestroyCallback* callback function.

When a driver creates an object, it sometimes allocates object-specific memory buffers and stores the buffer pointers in the object's [context space](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-context-space). The driver's [EvtCleanupCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_cleanup) or *EvtDestroyCallback* callback function can deallocate these memory buffers.

For more information about deleting framework objects, see [Framework Object Life Cycle](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-life-cycle).

Typically, the framework calls the *EvtDestroyCallback* callback function at IRQL <= DISPATCH_LEVEL. However, the framework calls the callback function at IRQL = PASSIVE_LEVEL in the following situations:

* The object's handle type is WDFDEVICE, WDFDRIVER, WDFDPC, WDFINTERRUPT, WDFIOTARGET, WDFQUEUE, WDFSTRING, WDFTIMER, or WDFWORKITEM.
* The object's handle type is WDFMEMORY or WDFLOOKASIDE, and the driver has specified **PagedPool** for the *PoolType* parameter to [WdfMemoryCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorycreate) or [WdfLookasideListCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdflookasidelistcreate).

Beginning with version 1.9 of the framework, the *wdfroletypes.h* header file contains some alternative, object type-specific, function types for the *EvtDestroyCallback* callback function. These alternative types help verification tools to determine whether the driver is properly using the callback function. Use the following table to determine which function type to use.

| Object Type | Function Type |
| --- | --- |
| Device object | EVT_WDF_DEVICE_CONTEXT_DESTROY |
| I/O queue object | EVT_WDF_IO_QUEUE_CONTEXT_DESTROY_CALLBACK |
| File object | EVT_WDF_FILE_CONTEXT_DESTROY_CALLBACK |
| All other objects | EVT_WDF_OBJECT_CONTEXT_DESTROY |

## See also

[EvtCleanupCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_cleanup)

[WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes)