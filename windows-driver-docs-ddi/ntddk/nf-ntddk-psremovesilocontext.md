# PsRemoveSiloContext function

## Description

This routine removes an object that was inserted in the *Silo*.

## Parameters

### `Silo` [in]

The silo from which the object is to be removed. This parameter is required and it cannot be **NULL**.

### `ContextSlot` [in]

A slot allocated by the [PsAllocSiloContextSlot](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-psallocsilocontextslot) routine.

### `RemovedSiloContext`

A pointer to a caller-allocated variable that receives the address of the removed object. This parameter is optional and can be **NULL**.

## Return value

The following NT status codes are returned.

| Return code | Description |
| --- | --- |
| **STATUS_NOT_FOUND** | The slot is empty. This is an error code. |
| **STATUS_NOT_SUPPORTED** | The slot is read-only and it cannot be modified. This is an error code. |
| **STATUS_SUCCESS** | The operation completed successfully. |

## Remarks

In a successful call to **PsRemoveSiloContext** where the *RemovedSiloContext* parameter is not **NULL** and does not point to **NULL**, the caller must decrement the object that the *RemovedSiloContext* parameter points to, by calling [PsDereferenceSiloContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-psdereferencesilocontext) when it is no longer needed.