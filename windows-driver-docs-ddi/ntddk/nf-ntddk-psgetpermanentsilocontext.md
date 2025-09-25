# PsGetPermanentSiloContext function

## Description

This routine retrieves an object that was inserted in the *Silo* without incrementing the reference count.

## Parameters

### `Silo` [in]

The silo in which the object was inserted. This parameter is required and it cannot be **NULL**.

### `ContextSlot` [in]

The read-only slot that was previously allocated by[PsAllocSiloContextSlot](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-psallocsilocontextslot) and made read-only by [PsMakeSiloContextPermanent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-psmakesilocontextpermanent).

### `ReturnedSiloContext`

A pointer to a caller-allocated variable that receives the address of the existing object. This parameter is required and it cannot be **NULL**.

## Return value

The following NT status codes are returned.

| Return code | Description |
| --- | --- |
| **STATUS_NOT_FOUND** | The slot is empty. This is an error code. |
| **STATUS_NOT_SUPPORTED** | The slot is not read-only and it cannot safely retrieve the object. This is an error code. |
| **STATUS_SUCCESS** | The operation completed successfully. |

## Remarks

A successful call to **PsGetPermanentSiloContext** does not increment the reference count on the object that the *ReturnedSiloContext* parameter points to. The returned object pointer is valid as long as there is a valid reference on the silo object.