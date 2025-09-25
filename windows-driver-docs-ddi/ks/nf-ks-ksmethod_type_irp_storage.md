## Description

This macro accesses the type of method as described in the [**KSMETHOD_ITEM**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksmethod_item). If the method will be processed asynchronously using [KsDispatchSpecificMethod](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksdispatchspecificmethod), this storage must be maintained intact.

## Parameters

### `Irp` [in]

Specifies the IRP passed to the handler routine.

## Remarks

The relevant KSMETHOD_ITEM structure is extracted from **Irp->Tail.Overlay.DriverContext**. Parameters in **DriverContext** are initialized by [KsMethodHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksmethodhandler) and [KsMethodHandlerWithAllocator](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksmethodhandlerwithallocator).

The macro is defined as follows:

```cpp
#define KSMETHOD_TYPE_IRP_STORAGE(Irp)  (*(ULONG_PTR*)(&(Irp)->Tail.Overlay.DriverContext[2]))
```

## See also

[**KSMETHOD**](https://learn.microsoft.com/windows-hardware/drivers/stream/ksmethod-structure)

[**KSMETHOD_ITEM**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksmethod_item)

[**KSMETHOD_SET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksmethod_set)

[KsFastMethodHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfastmethodhandler)

[KsMethodHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksmethodhandler)

[KsMethodHandlerWithAllocator](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksmethodhandlerwithallocator)