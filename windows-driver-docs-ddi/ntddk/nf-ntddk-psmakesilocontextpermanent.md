# PsMakeSiloContextPermanent function

## Description

This routine makes the slot in a silo instance read-only, allowing the object in the slot to be retrieved without affecting the reference count on that object.

## Parameters

### `Silo` [in]

The silo in which the slot resides. This parameter is required and it cannot be **NULL**.

### `ContextSlot` [in]

The slot to make read-only. The slot must be previously allocated by the [PsAllocSiloContextSlot](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-psallocsilocontextslot) routine.

## Return value

The following NT status codes are returned.

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | The slot does not contain a valid object. This is an error code. |
| **STATUS_NOT_FOUND** | The slot has not been allocated. This is an error code. |
| **STATUS_SUCCESS** | The operation completed successfully. |

## Remarks

Before calling this routine, the slot must contain a valid object. After it completes, the [PsReplaceSiloContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-psreplacesilocontext) and [PsRemoveSiloContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-psremovesilocontext) routines will fail with **STATUS_NOT_SUPPORTED**.