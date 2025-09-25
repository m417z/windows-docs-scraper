# PFNKSITEMFREECALLBACK callback function

## Description

A streaming minidriver's *KStrItemFreeCallback* routine is called to free a previously allocated create item. *KStrItemFreeCallback* allows the minidriver to perform any cleanup, including flushing security descriptor changes, if necessary.

## Parameters

### `CreateItem` [in]

Specifies a create item that was previously allocated by [KsAllocateObjectCreateItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksallocateobjectcreateitem).

## Remarks

The *Context* parameter of the [KSOBJECT_CREATE_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksobject_create_item) structure must contain sufficient information to perform cleanup for the create item.

The *Flags* member of the KSOBJECT_CREATE_ITEM structure indicates if it is necessary to flush security descriptor changes.

## See also

[KSOBJECT_CREATE_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksobject_create_item)

[KsAllocateObjectCreateItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksallocateobjectcreateitem)