# PsInsertSiloContext function

## Description

This routine inserts an object in an empty slot in a *Silo*.

## Parameters

### `Silo` [in]

A pointer to a silo. This parameter is required and it cannot be **NULL**.

### `ContextSlot` [in]

A slot allocated by the [PsAllocSiloContextSlot](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-psallocsilocontextslot) routine.

### `SiloContext` [in]

A pointer to the object created by the [PsCreateSiloContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pscreatesilocontext) routine. The object must be created using the same silo pointer as the one specified in this routine. This parameter is required and it cannot be **NULL**.

## Return value

The following NT status codes are returned.

| Return code | Description |
| --- | --- |
| **STATUS_INSUFFICIENT_RESOURCES** | There are no resources in the system to perform the insert. This is an error code. |
| **STATUS_NOT_SUPPORTED** | The slot is not empty. This is an error code. |
| **STATUS_SUCCESS** | The operation completed successfully. |