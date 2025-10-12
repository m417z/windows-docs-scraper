## Description

This macro retrieves a pointer to the [**KSEVENT_ENTRY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksevent_entry) structure stored in *Irp*. This information is initialized only for enable requests; it is not initialized for basic support requests. If the event enable is to be handled asynchronously, this storage location must be maintained intact.

## Parameters

### `Irp`

Contains a pointer to a **KSEVENT_ENTRY** structure.

## Remarks

The macro is defined as follows:

```cpp
#define KSEVENT_ENTRY_IRP_STORAGE(Irp)   (*(PKSEVENT_ENTRY*)&(Irp)->Tail.Overlay.DriverContext[0])
```