# DlMapMemory function

## Description

Maps a range of bus-relative physical addresses of display memory into system space or into the virtual address space of a user-mode process.

## Parameters

### `DeviceHandle`

A handle that represents a display adapter.

### `TranslatedAddress`

The bus-relative base address of the range to map.

### `Length`

On input, specifies the number of bytes of memory to map.

### `InIoSpace`

Pointer to a variable that indicates the location of the range.

### `VirtualAddress`

Pointer to a variable that, on input, is either **NULL** or a handle to a user-mode process.

## Return value

This function returns VP_STATUS.

## Remarks

## See also