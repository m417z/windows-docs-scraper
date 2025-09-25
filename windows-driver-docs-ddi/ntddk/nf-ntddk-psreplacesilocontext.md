# PsReplaceSiloContext function

## Description

This routine inserts an object in a *Silo*.

## Parameters

### `Silo` [in]

A pointer to a silo. This parameter is required and it cannot be **NULL**.

### `ContextSlot` [in]

A slot allocated by the [PsAllocSiloContextSlot](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-psallocsilocontextslot) routine.

### `NewSiloContext` [in]

A pointer to the object created by the [PsCreateSiloContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pscreatesilocontext) routine. The object must be created using the same silo pointer as the one specified in this routine. This parameter is required and it cannot be **NULL**.

### `OldSiloContext` [optional]

A pointer to a caller-allocated variable that receives the address of the existing object. This parameter is optional and can be **NULL**. The address that the parameter receives can be **NULL**.

## Return value

The following NT status codes are returned.

| Return code | Description |
| --- | --- |
| **STATUS_INSUFFICIENT_RESOURCES** | There are no resources in the system to perform the insert. This is an error code. |
| **STATUS_NOT_SUPPORTED** | The slot is read-only and it cannot be modified. This is an error code. |
| **STATUS_SUCCESS** | The operation completed successfully. |

## Remarks

A successful call to **PsReplaceSiloContext** increments the reference count on *NewSiloContext*. If **PsReplaceSiloContext** fails, the reference count remains unchanged. In either case, the caller of **PsReplaceSiloContext** must call [PsDereferenceSiloContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-psdereferencesilocontext) to decrement the **PsReplaceSiloContext** object. If **PsReplaceSiloContext** fails and if the *OldSiloContext* parameter is not **NULL** and does not point to **NULL** then **NULL** is a referenced pointer. After the routine completes, the caller must call **PsDereferenceSiloContext** to decrement the object that the **NULL** parameter points to.