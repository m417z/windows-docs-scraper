# PsInsertPermanentSiloContext function

## Description

This routine inserts an object in an empty slot in a *Silo*.

## Parameters

### `Silo` [in]

The silo in which the object is to be inserted. This parameter is required and it cannot be **NULL**.

### `ContextSlot` [in]

The slot in which the object is to be inserted. A slot allocated by the [PsAllocSiloContextSlot](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-psallocsilocontextslot) routine.

### `SiloContext` [in]

The object to be inserted, created by the [PsCreateSiloContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pscreatesilocontext) routine. The object must be created using the same silo as specified in the *Silo* parameter. This parameter is required and it cannot be **NULL**.

## Return value

The following NT status codes are returned.

| Return code | Description |
| --- | --- |
| **STATUS_INSUFFICIENT_RESOURCES** | There are no resources in the system to perform the insert. This is an error code. |
| **STATUS_NOT_SUPPORTED** | The slot is not empty. This is an error code. |
| **STATUS_SUCCESS** | The operation completed successfully. |

## Remarks

A successful call to **PsInsertPermanentSiloContext** increments the reference count on *SiloContext*. If **PsInsertPermanentSiloContext** fails, the reference count remains unchanged. In either case, after the routine completes, the caller must call [PsDereferenceSiloContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-psdereferencesilocontext) to decrement the *SiloContext* object.