# FILE_SEGMENT_ELEMENT structure

## Description

Represents a segment of an I/O buffer for scatter/gather read/write actions.

## Members

### `Buffer`

A pointer to the data for the scatter/gather read/write action.

Assigning a pointer to the **Buffer** member will sign-extend the value if the code is compiled as 32-bits; this can break large-address aware applications running on systems configured with [4-Gigabyte Tuning](https://learn.microsoft.com/windows/desktop/Memory/4-gigabyte-tuning) or running under WOW64 on 64-bit Windows. Therefore, use the **PtrToPtr64** macro when assigning pointers to **Buffer**.

### `Alignment`

An integer representation of the **Buffer**. The system uses this member to validate that the buffer is properly aligned. Applications typically operate on the **Buffer** member.

## Remarks

## See also

[WriteFileGather function](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-writefilegather), [ReadFileScatter function](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-readfilescatter)