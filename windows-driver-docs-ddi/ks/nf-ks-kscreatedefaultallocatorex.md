# KsCreateDefaultAllocatorEx function

## Description

Creates a default allocator that uses the specified memory pool and associates the *IoGetCurrentIrpStackLocation(pIrp)->FileObject* with this allocator using an internal dispatch table (KSDISPATCH_TABLE).

## Parameters

### `Irp` [in]

Contains the IRP with the allocator create request being handled.

### `InitializeContext` [in, optional]

Optionally contains a context to use with an external allocator. This is only used as the initialization context to the optional InitializeAllocator callback when creating an allocator context. The parameter is not otherwise used. If an external allocator is not provided, this parameter must be set to **NULL**.

### `DefaultAllocate` [in, optional]

Optionally contains an external allocate function that is used in place of the default pool allocation. If this is **NULL**, default allocation is used.

### `DefaultFree` [in, optional]

Optionally contains an external free function that is used in place of the default pool allocation. If an external allocator is not provided, this parameter must be set to **NULL**.

### `InitializeAllocator` [in, optional]

Optionally contains an external allocator initialization function to which the InitializeContext parameter is passed. This function is expected to return an allocator context based on the allocator framing. If an external allocator is not provided, this parameter must be set to **NULL**.

### `DeleteAllocator` [in, optional]

Optionally contains an external allocator delete function that is used for external allocators. If an external allocator is not provided, this parameter must be set to **NULL**.

## Return value

Returns STATUS_SUCCESS, else an error on default allocator creation failure. Does not complete the IRP or set the status in the IRP.

## Remarks

Before calling this routine, the **KSCREATE_ITEM_IRP_STORAGE(Irp)** macro should return a pointer to the [KSOBJECT_CREATE_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksobject_create_item) structure that is the create item for this allocator. **KsCreateDefaultAllocatorEx** sets **FsContext** to point to the return value of this macro. As such, **FsContext** can later be used for security descriptor queries or changes.

You can find **KSCREATE_ITEM_IRP_STORAGE(Irp)** and related macros in *ks.h*.