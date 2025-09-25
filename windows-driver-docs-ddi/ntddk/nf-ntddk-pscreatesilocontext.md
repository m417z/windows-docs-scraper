# PsCreateSiloContext function

## Description

This routine creates an object that will be inserted in a *Silo*.

## Parameters

### `Silo` [in]

A pointer to a silo. This parameter is required and it cannot be **NULL**.

### `Size` [in]

The size, in bytes, of the portion of the object defined by the caller.

### `PoolType` [in]

The type of pool to allocate from. This parameter is required and must be one of the following: **NonPagedPoolNx** or **PagedPool**.

### `ContextCleanupCallback` [in, optional]

A pointer to a [SILO_CONTEXT_CLEANUP_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-silo_context_cleanup_callback) callback function. The function will be called when the returned object has zero references to it. This parameter is optional and can be **NULL**.

### `ReturnedSiloContext`

A pointer to a caller-allocated variable that receives the address of the newly created object.

## Return value

The following NT status codes are returned.

| Return code | Description |
|--|--|
| **STATUS_INSUFFICIENT_RESOURCES** | The routine encountered a pool allocation failure. This is an error code. |
| **STATUS_INVALID_PARAMETER** | The pool type is not valid. This is an error code. |
| **STATUS_SUCCESS** | The operation completed successfully. |