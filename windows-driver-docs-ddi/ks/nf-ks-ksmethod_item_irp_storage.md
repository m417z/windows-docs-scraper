## Description

This macro accesses a pointer to the relevant [**KSMETHOD_ITEM**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksmethod_item). Note that this pointer is only set when using [KsMethodHandlerWithAllocator](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksmethodhandlerwithallocator).

## Parameters

### `Irp` [in]

Specifies the IRP passed to the handler routine.

## Remarks

The pointer to a KSMETHOD_ITEM structure is extracted from `Irp->Tail.Overlay.DriverContext`. Parameters in **DriverContext** are initialized by [**KsMethodHandler**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksmethodhandler) and [**KsMethodHandlerWithAllocator**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksmethodhandlerwithallocator).

The macro is defined as follows:

```cpp
#define KSMETHOD_ITEM_IRP_STORAGE(Irp)  (*(const KSMETHOD_ITEM**)&(Irp)->;Tail.Overlay.DriverContext[3])
```

## See also

[KSMETHOD](https://learn.microsoft.com/windows-hardware/drivers/stream/ksmethod-structure)

[KSMETHOD_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksmethod_item)

[KSMETHOD_SET](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksmethod_set)

[KsFastMethodHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfastmethodhandler)

[KsMethodHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksmethodhandler)

[KsMethodHandlerWithAllocator](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksmethodhandlerwithallocator)