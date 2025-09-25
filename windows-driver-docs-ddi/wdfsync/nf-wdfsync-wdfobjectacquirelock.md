# WdfObjectAcquireLock function

## Description

[Applies to KMDF and UMDF]

The **WdfObjectAcquireLock** method acquires an object's synchronization lock.

## Syntax

```cpp
VOID WdfObjectAcquireLock(
  _In_ WDFOBJECT Object
);
```
## Parameters

### `Object` [in]

A handle to a framework device object or a framework queue object.

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

A driver can call the **WdfObjectAcquireLock** method to acquire the synchronization lock that is associated with a specified framework device object or framework queue object. The method does not return until the lock has been acquired.

When the driver no longer needs the object's synchronization lock, it must call [WdfObjectReleaseLock](https://learn.microsoft.com/previous-versions/ff548765(v=vs.85)).

If the driver specified **WdfExecutionLevelPassive** for the **ExecutionLevel** member of the specified object's [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure, the driver must call **WdfObjectAcquireLock** at IRQL <= APC_LEVEL. **WdfObjectAcquireLock** acquires a [fast mutex](https://learn.microsoft.com/windows-hardware/drivers/kernel/fast-mutexes-and-guarded-mutexes) and returns at the caller's IRQL. (In this case, **WdfObjectAcquireLock** also calls [KeEnterCriticalRegion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keentercriticalregion) before returning so that [normal kernel APCs](https://learn.microsoft.com/windows-hardware/drivers/kernel/types-of-apcs) are disabled.)

If the driver did *not* specify **WdfExecutionLevelPassive** for the **ExecutionLevel** member of the specified object's WDF_OBJECT_ATTRIBUTES structure, the driver must call **WdfObjectAcquireLock** at IRQL <= DISPATCH_LEVEL. **WdfObjectAcquireLock** acquires a [spin lock](https://learn.microsoft.com/windows-hardware/drivers/kernel/spin-locks) and returns at IRQL = DISPATCH_LEVEL.

For more information about synchronization locks, see [Synchronization Techniques for Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/synchronization-techniques-for-wdf-drivers).

## See also

[WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes)

[KeEnterCriticalRegion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keentercriticalregion)

[WdfObjectReleaseLock](https://learn.microsoft.com/previous-versions/ff548765(v=vs.85))