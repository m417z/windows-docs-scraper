# WdfObjectReleaseLock function

## Description

[Applies to KMDF and UMDF]

The **WdfObjectReleaseLock** method releases an object's synchronization lock.

## Syntax

```cpp
VOID WdfObjectReleaseLock(
  _In_ WDFOBJECT Object
);
```

## Parameters

### `Object` [in]

A handle to a framework device object or a framework queue object.

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

The **WdfObjectReleaseLock** method releases the synchronization lock that a driver acquired by previously calling [WdfObjectAcquireLock](https://learn.microsoft.com/previous-versions/ff548721(v=vs.85)). **WdfObjectReleaseLock** also restores the driver's IRQL to the value that it had before the driver called **WdfObjectAcquireLock**.

For more information about synchronization locks, see [Synchronization Techniques for Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/synchronization-techniques-for-wdf-drivers).

## See also

[WdfObjectAcquireLock](https://learn.microsoft.com/previous-versions/ff548721(v=vs.85))