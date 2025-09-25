## Description

This routine frees the specified slot and makes it available in the system. It undoes the effects of the [PsAllocSiloContextSlot](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-psallocsilocontextslot) routine.

## Parameters

### `ContextSlot` [in]

A slot allocated by the [PsAllocSiloContextSlot](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-psallocsilocontextslot) routine.

> [!WARNING]
> Setting this parameter to a slot that is still in use causes the system to execute bug check.

## Return value

The following NT status codes are returned:

| Return code | Description |
|---|---|
| **STATUS_INVALID_PARAMETER** | The slot is not allocated in the system. This is an error code. |
| **STATUS_SUCCESS** | The operation completed successfully. |

## See also

[PsAllocSiloContextSlot](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-psallocsilocontextslot)