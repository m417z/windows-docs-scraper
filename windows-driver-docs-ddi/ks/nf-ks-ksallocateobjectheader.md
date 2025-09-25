# KsAllocateObjectHeader function

## Description

The **KsAllocateObjectHeader** function initializes the required file context header.

## Parameters

### `Header` [out]

Points to the caller-allocated location in which to return a pointer to the initialized **KSOBJECT_HEADER** if successful.

### `ItemsCount` [in]

Specifies the number of object create items in the *ItemsList* to be added to the object header once the header is allocated. This value should be zero if *ItemsList* is **NULL**.

### `ItemsList` [in, optional]

Optionally specifies a pointer to a caller-allocated buffer containing a series of [KSOBJECT_CREATE_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksobject_create_item) structures to be added to the object header. Must be set to **NULL** if there are no object create items.

### `Irp` [in]

Points to the IRP, of major function [IRP_MJ_CREATE](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-create), that contains the necessary information to complete the creation of the object header.

### `Table` [in]

Points to an initialized dispatch table for this file object.

## Return value

The **KsAllocateObjectHeader** function returns **STATUS_SUCCESS** if successful or **STATUS_INSUFFICIENT_RESOURCES** if not enough resources are available to fulfill the request.

## Remarks

Before calling this routine the driver must allocate system-resident storage for a [KSDISPATCH_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksdispatch_table) and initialize the dispatch table. The memory for this dispatch table cannot be released until **KsFreeObjectHeader** is called.

**KsAllocateObjectHeader** allocates the memory for the **KSOBJECT_HEADER** structure and returns a pointer to the header at *Header*. Drivers must not attempt to free the memory themselves, but rather call **KsFreeObjectHeader** when all operations requiring this object header have been completed.

If subobjects exist for a given device, the driver must, before calling **KsAllocateObjectHeader**, allocate a buffer of either paged or nonpaged memory of sufficient size to hold a [KSOBJECT_CREATE_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksobject_create_item) structure for each subobject. For example:

```cpp
/* Allocate a buffer for 4 subobjects for a given streaming device */
PKSOBJECT_CREATE_ITEM createBuffer ;
ULONG bufferSize  = (sizeof (KSOBJECT_CREATE_ITEM)) * 4 ;

createBuffer = (PKSOBJECT_CREATE_ITEM)
               ExAllocatePoolWithTag (PagedPool, bufferSize) ;
```

Drivers must not free the memory allocated for the subobject [KSOBJECT_CREATE_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksobject_create_item) list until after calling **KsFreeDeviceHeader**. Failure to do so can result in a bug check condition.

## See also

[KSOBJECT_CREATE_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksobject_create_item)

[KsFreeDeviceHeader](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfreedeviceheader)

[KsFreeObjectHeader](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfreeobjectheader)