# PsGetSiloContext function

## Description

This routine retrieves the silo context from the specified silo and slot.

## Parameters

### `Silo` [in]

The silo where the silo context is to exist. This parameter is required and it cannot be **NULL**.

### `ContextSlot` [in]

The slot where the silo context is to exist. A slot allocated by the [PsAllocSiloContextSlot](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-psallocsilocontextslot) routine.

### `ReturnedSiloContext`

Receives a referenced pointer to the silo context. On failure, the value received will be **NULL**.

## Return value

The following NT status codes are returned.

| Return code | Description |
| --- | --- |
| **STATUS_NOT_FOUND** | Status code if the silo context is not found. |
| **STATUS_INVALID_PARAMETER** | Status code if an invalid slot number was supplied as the *ContextSlot* parameter. |
| **STATUS_SUCCESS** | The operation completed successfully. |

## Remarks

The **PsGetSiloContext** routine retrieves an object that was inserted in the specified silo. A successful call to this routine increments the reference count on the object that the *ReturnedSiloContext* parameter points to. The object that the *ReturnedSiloContext* parameter points to, must be decremented by calling [PsDereferenceSiloContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-psdereferencesilocontext) when it is no longer needed.
A context slot may go empty if the silo is being terminated by either having no more processes or a specific call to **NtTerminateJobObject**. The return status in this case is **STATUS_NOT_FOUND**.