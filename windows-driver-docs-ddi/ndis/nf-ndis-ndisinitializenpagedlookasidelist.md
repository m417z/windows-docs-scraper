# NdisInitializeNPagedLookasideList function

## Description

The
**NdisInitializeNPagedLookasideList** function initializes a lookaside list. After a successful
initialization, nonpaged fixed-size blocks can be allocated from and freed to the lookaside list.

## Parameters

### `Lookaside` [in]

A pointer to an
[NPAGED_LOOKASIDE_LIST](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure that
contains the caller-supplied lookaside list head to be initialized. The structure must be 16-byte aligned on 64-bit platforms. The driver must provide a list head
that is resident—that is, in nonpaged system space.

### `Allocate` [in, optional]

A function entry point that is either **NULL** or specifies the entry point of a caller-supplied
*Allocate* function that will allocate an entry of the size that is specified in the
*Size* member whenever it is called. If
*Allocate* is **NULL**, the
[NdisAllocateFromNPagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatefromnpagedlookasidelist) function subsequently allocates entries on behalf of the
caller. If the caller provides an
*Allocate* function, it also must provide a
*Free* function.

### `Free` [in, optional]

A function entry point that is either **NULL** or specifies the entry point of a caller-supplied
*Free* function that will free an entry of the size that is specified in the
*Size* member whenever it is called. If
*Free* is **NULL**, the
[NdisFreeToNPagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreetonpagedlookasidelist) function subsequently frees entries on behalf of the caller.

### `Flags` [in]

Must be zero. This parameter is reserved.

### `Size` [in]

The size, in bytes, of each entry to be subsequently allocated from the lookaside list.

### `Tag` [in]

A caller-supplied pool tag for lookaside list entries. The
*Tag* is a string of four characters that is delimited by single quote marks (for example, 'derF').
The characters are usually specified in reverse order so they are easier to read when dumping pool or
tracking pool usage in the debugger.

### `Depth` [in]

Must be zero. This parameter is also reserved.

## Remarks

**NdisInitializeNPagedLookasideList** initializes the caller-supplied list head but allocates no memory
for list entries. The initial entries are allocated on an as-needed basis either with calls to the
[NdisAllocateFromNPagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatefromnpagedlookasidelist) function or by the driver-supplied
*Allocate* callback function at the
*Allocate* parameter. The list is populated as the driver frees entries back to the list with the
[NdisFreeToNPagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreetonpagedlookasidelist) function. Entries collect on the list until a system-determined but
dynamically sized limit is reached. Then, any surplus entries in the lookaside list are returned to
nonpaged pool, either by
**NdisFreeToNPagedLookasideList** or with calls to the driver-supplied
*Free* callback function at the
*Free* parameter.

All entries in the lookaside list are of the same size, which is specified in the
*Size* parameter. A lookaside list is particularly useful to drivers that must dynamically allocate
and free fixed-size context areas in which to maintain run-time state about their outstanding I/O
operations. For instance, connection-oriented NDIS drivers are likely to find lookaside lists
particularly useful because such drivers usually maintain a dynamic set of context areas to track
outgoing and incoming calls.

It is more efficient for a driver to allow the
[NdisAllocateFromNPagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatefromnpagedlookasidelist) and
[NdisFreeToNPagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreetonpagedlookasidelist) functions to manage the allocation and deallocation of entries (see
the
[ExAllocatePoolWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithtag) and
[ExFreePool](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-exfreepool) functions). However, a driver that
tracks state internally about its memory usage might supply
*Allocate* and
*Free* functions to
**NdisInitializeNPagedLookasideList**.

Callers of
**NdisInitializeNPagedLookasideList** must be running at IRQL <= DISPATCH_LEVEL, but are usually
running at PASSIVE_LEVEL.

## See also

[ExAllocatePoolWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithtag)

[ExFreePool](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-exfreepool)

[NPAGED_LOOKASIDE_LIST](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)

[NdisAllocateFromNPagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatefromnpagedlookasidelist)

[NdisDeleteNPagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisdeletenpagedlookasidelist)

[NdisFreeToNPagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreetonpagedlookasidelist)