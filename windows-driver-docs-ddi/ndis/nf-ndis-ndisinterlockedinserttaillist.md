# NdisInterlockedInsertTailList macro

## Description

The
**NdisInterlockedInsertTailList** function inserts an entry, usually a packet, at the tail of a doubly
linked list so that access to the list is synchronized in a multiprocessor-safe way.

## Parameters

### `_ListHead` [in]

A pointer to the head of the doubly linked list into which an entry is to be inserted.

### `_ListEntry` [in]

A pointer to the entry to be inserted at the end of the list.

### `_SpinLock` [in]

A pointer to a caller-supplied spin lock, used to synchronize access to the list.

## Remarks

Before calling
**NdisInterlockedInsertTailList**, a driver must initialize the variable at
*ListHead* with the
[NdisInitializeListHead](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisinitializelisthead) function and
the variable at
*SpinLock* with the
[NdisAllocateSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatespinlock) function. The
driver also must provide resident storage for these variables and for its internal queue.

The caller-supplied spin lock prevents any other function from accessing the driver's internal queue
while
**NdisInterlockedInsertTailList** is inserting the given entry, even when the driver is running on a
multiprocessor machine.

**NdisInterlockedInsertTailList** raises the IRQL to DISPATCH_LEVEL when it acquires the given spin
lock and restores the original IRQL before it returns control. Consequently, any driver function that
calls
**NdisInterlockedInsertTailList** cannot be pageable code.

To convert a returned value back to the address of the inserted entry, a driver can use the
[**CONTAINING_RECORD**](https://learn.microsoft.com/windows/win32/api/ntdef/nf-ntdef-containing_record) macro.

If
**NdisInterlockedInsertTailList** is called at IRQL >= DISPATCH_LEVEL, the storage for the
*ListHead* parameter and the list entries must be resident.

## See also

[**CONTAINING_RECORD**](https://learn.microsoft.com/windows/win32/api/ntdef/nf-ntdef-containing_record)

[NdisAllocateSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatespinlock)

[NdisInitializeListHead](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisinitializelisthead)

[NdisInterlockedInsertHeadList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisinterlockedinsertheadlist)

[NdisInterlockedRemoveHeadList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisinterlockedremoveheadlist)