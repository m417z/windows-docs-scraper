## Description

The **KsDiscard** macro removes a given item from an object bag.

## Parameters

### `Object` [in]

The item pointed to by *Pointer* is removed from the object bag associated with this object. Can be of type [**KSDEVICE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice), [**KSFILTERFACTORY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilterfactory), [**KSFILTER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter), or [**KSPIN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin).

### `Pointer` [in]

A pointer to the item to be removed from the requested object's bag.

## Remarks

This macro wraps and assumes the return value of [KsRemoveItemFromObjectBag](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksremoveitemfromobjectbag), which is **ULONG**.

This function is implemented as a C-style preprocessing macro in the *Ks.h* header.

**KsDiscard** calls **KsRemoveItemFromObjectBag**, passing the object bag associated with *Object* (*Object->Bag*), the item specified by *Pointer*, and **TRUE** for the *Free* parameter.

## See also

[**KSDEVICE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice)

[**KSFILTER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter)

[**KSFILTERFACTORY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilterfactory)

[**KSPIN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin)

[KsRemoveItemFromObjectBag](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksremoveitemfromobjectbag)