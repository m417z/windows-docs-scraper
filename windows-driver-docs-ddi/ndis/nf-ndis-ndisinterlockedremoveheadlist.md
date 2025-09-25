# NdisInterlockedRemoveHeadList macro

## Description

The
**NdisInterlockedRemoveHeadList** function removes an entry, usually a packet, from the head of a doubly
linked list so that access to the list is synchronized in a multiprocessor-safe way.

## Syntax
```cpp
PLIST_ENTRY NdisInterlockedRemoveHeadList(
  [in]  _ListHead,
  [in]  _SpinLock
);
```

## Parameters

### `_ListHead` [in]

A pointer to the head of the doubly linked list from which an entry is to be removed.

### `_SpinLock` [in]

A pointer to a caller-supplied spin lock, used to synchronize access to the list.

## Return value

**NdisInterlockedRemoveHeadList** returns a pointer to the [LIST_ENTRY](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-list_entry) structure removed from the list. If the list was empty, the routine returns **NULL**.

## Remarks

Before calling any
**NdisInterlocked..List** function, a driver must initialize the variable at
*ListHead* with the
[NdisInitializeListHead](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisinitializelisthead) function and
the variable at
*SpinLock* with the
[NdisAllocateSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatespinlock) function. The
driver also must provide resident storage for these variables and for its internal queue.

Before calling
**NdisInterlockedRemoveHeadList**, entries are queued with one or more calls to the
**NdisInterlockedInsert..List** functions.

The caller-supplied spin lock prevents any other function from accessing the driver's internal queue
while
**NdisInterlockedRemoveHeadList** is removing an entry, even when the driver is running on a
multiprocessor computer.

**NdisInterlockedRemoveHeadList** raises the IRQL to DISPATCH_LEVEL when it acquires the given spin
lock and restores the original IRQL before it returns control. Consequently, any driver function that
calls
**NdisInterlockedRemoveHeadList** cannot be pageable code.

To convert a returned value back to the address of the inserted entry, a driver can use the
[**CONTAINING_RECORD**](https://learn.microsoft.com/windows/win32/api/ntdef/nf-ntdef-containing_record) macro.

If
**NdisInterlockedRemoveHeadList** is called at IRQL >= DISPATCH_LEVEL, the storage for the
*ListHead* parameter must be resident.

## See also

[**CONTAINING_RECORD**](https://learn.microsoft.com/windows/win32/api/ntdef/nf-ntdef-containing_record)

[NdisAllocateSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatespinlock)

[NdisInitializeListHead](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisinitializelisthead)

[NdisInterlockedInsertHeadList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisinterlockedinsertheadlist)

[NdisInterlockedInsertTailList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisinterlockedinserttaillist)