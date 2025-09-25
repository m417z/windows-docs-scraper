# KsMoveIrpsOnCancelableQueue function

## Description

The **KsMoveIrpsOnCancelableQueue** function moves the specified IRPs from the *SourceList* parameter to the *DestinationList* parameter depending on the value returned from the minidriver-defined [KStrIrpListCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnksirplistcallback) function.

## Parameters

### `SourceList` [in, out]

Specifies the head of the queue from which to remove the IRPs.

### `SourceLock` [in]

Pointer to the driver's spin lock for source queue access.

### `DestinationList` [in, out]

Specifies the head of the queue on which to add the IRPs.

### `DestinationLock` [in, optional]

Optionally contains a pointer to driver's spin lock for destination queue access. If this is not provided, the *SourceLock* parameter is assumed to control both queues. If provided, this lock is always acquired after the *SourceLock* parameter. If the destination list has a separate spin lock, the system-wide Cancel Spin Lock is first acquired in order to move IRPs and allow the KSQUEUE_SPINLOCK_IRP_STORAGE() spin lock to be updated.

### `ListLocation` [in]

Indicates whether the IRPs should be enumerated from the head or the tail of the source queue. Any IRPs that are moved are placed on the destination queue's opposite end so that ordering is maintained.

### `ListCallback` [in]

Specifies the minidriver-defined [KStrIrpListCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnksirplistcallback) function to call to indicate whether a specific IRP should be moved from *SourceList* to *DestinationList*, or if enumeration should be terminated.

### `Context` [in]

Context passed to *ListCallback*.

## Return value

Returns STATUS_SUCCESS if the list was completely enumerated; otherwise, returns any warning or error returned by the minidriver-defined *KStrIrpListCallback* callback function that interrupted enumeration.

## Remarks

An IRP is moved if the [KStrIrpListCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnksirplistcallback) function indicates that it should be moved, whether it is currently acquired. If *KStrIrpListCallback* returns STATUS_SUCCESS, the IRP is moved. If it returns STATUS_NO_MATCH, the IRP is not moved. Any other return warning or error value will terminate enumeration and be returned by the function. The STATUS_NO_MATCH value should not be returned as an error by *KStrIrpListCallback*. *KStrIrpListCallback* is called at DISPATCH_LEVEL. *KStrIrpListCallback* is always called at least once at the end with a **NULL** IRP value to complete list enumeration.

**KsMoveIrpsOnCancelableQueue** continues through the list until the callback function indicates that the search should be terminated, or the end of the list is reached. **KsMoveIrpsOnCancelableQueue** minimizes the use of the system-wide Cancel Spin Lock by using the provided spin locks to synchronize access when possible. **KsMoveIrpsOnCancelableQueue** does not allow the cancel routine to be modified while moving IRPs.

The function can be called at DISPATCH_LEVEL or lower.

## See also

[KStrIrpListCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnksirplistcallback)