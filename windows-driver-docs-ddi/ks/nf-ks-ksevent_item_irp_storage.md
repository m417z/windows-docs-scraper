## Description

This macro retrieves a pointer to the [**KSEVENT_ITEM**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksevent_item) structure stored in *Irp*.

## Parameters

### `Irp`

Contains a pointer to a **KSEVENT_ITEM** structure.

## Remarks

The macro is defined as follows:

```cpp
#define KSMETHOD_ITEM_IRP_STORAGE(Irp)  (*(const KSMETHOD_ITEM**)&(Irp)->Tail.Overlay.DriverContext[3])
```