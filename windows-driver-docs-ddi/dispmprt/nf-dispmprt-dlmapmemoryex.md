# DlMapMemoryEx function

## Description

Maps a range of bus-relative physical addresses of display memory into system space or into the virtual address space of a user-mode process.

## Parameters

### `DeviceHandle`

A handle that represents a display adapter.

### `TranslatedAddress`

### `Length`

On input, specifies the number of bytes of memory to map.

### `InIoSpace`

Pointer to a variable that indicates the location of the range.

### `ProcessHandle`

### `VirtualAddress`

Pointer to a variable that, on input, is either **NULL** or a handle to a user-mode process.

### `MapToUserMode`

## Return value

This function returns NTSTATUS.

## Remarks

## See also