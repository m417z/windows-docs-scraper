# DlLockBuffer function

## Description

Probes the specified buffer, makes the buffer's memory pages resident in memory, and locks the physical pages mapped by the virtual address range.

## Parameters

### `DeviceHandle`

A handle that represents a display adapter.

### `BaseAddress`

Specifies the virtual address of the buffer to be locked.

### `Length`

Specifies the length in bytes of the buffer to be locked.

### `Operation`

Specifies the type of operation for which the caller wants the access rights probed and the pages locked.

## Return value

This function returns PVOID.

## Remarks

## See also