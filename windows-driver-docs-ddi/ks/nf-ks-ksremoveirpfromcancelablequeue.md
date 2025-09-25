# KsRemoveIrpFromCancelableQueue function

## Description

The **KsRemoveIrpFromCancelableQueue** function pops the next noncanceled IRP from the specified queue that can be canceled and removes its cancel status. The function searches the list until an IRP is found that has a cancel routine or until the end of the list is reached. The function minimizes the use of the cancel spin lock by using the provided spin lock to synchronize access in most cases. The function may be called at IRQ level DISPATCH_LEVEL or lower.

## Parameters

### `QueueHead` [in, out]

Points to the head of the queue from which to remove the IRP.

### `SpinLock` [in]

Points to driver's spin lock for queue access.

### `ListLocation` [in]

Indicates whether this IRP should come from the beginning or end of the queue.

### `RemovalOperation` [in]

Specifies whether the IRP is removed from the list or just acquired by setting the cancel function to **NULL**. If it is only acquired, the IRP must be later released with **KsReleaseIrpOnCancelableQueue** or completely removed with **KsRemoveSpecificIrpFromCancelableQueue**.

## Return value

The **KsRemoveIrpFromCancelableQueue** function returns the next noncanceled IRP on the list, or it returns **NULL** if none is found or if an IRP that has not already been acquired cannot be found.

## Remarks

These enumerations are used in the previous parameters to control where the IRP is removed from and how.

```cpp
typedef enum {
    KsListEntryTail,
    KsListEntryHead
} KSLIST_ENTRY_LOCATION;

typedef enum {
    KsAcquireOnly,
    KsAcquireAndRemove
} KSIRP_REMOVAL_OPERATION;
```

## See also

[KsReleaseIrpOnCancelableQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksreleaseirponcancelablequeue)

[KsRemoveSpecificIrpFromCancelableQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksremovespecificirpfromcancelablequeue)