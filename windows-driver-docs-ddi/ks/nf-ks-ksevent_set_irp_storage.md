## Description

This macro retrieves a pointer to the [**KSEVENT_SET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksevent_set) structure stored in *Irp*. This information is initialized only for basic support requests; it is not initialized for enable requests.

## Parameters

### `Irp`

Contains a pointer to a KSEVENT_SET structure.

## Remarks

The macro is defined as follows:

```cpp
#define KSMETHOD_SET_IRP_STORAGE(Irp)   (*(const KSMETHOD_SET**)&(Irp)->Tail.Overlay.DriverContext[0])
```