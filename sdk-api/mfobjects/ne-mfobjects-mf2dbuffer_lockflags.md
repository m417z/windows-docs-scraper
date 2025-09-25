# MF2DBuffer_LockFlags enumeration

## Description

Contains flags for the [IMF2DBuffer2::Lock2DSize](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imf2dbuffer2-lock2dsize) method.

## Constants

### `MF2DBuffer_LockFlags_LockTypeMask`

Reserved.

### `MF2DBuffer_LockFlags_Read:0x1`

Lock the buffer for reading.

### `MF2DBuffer_LockFlags_Write:0x2`

Lock the buffer for writing.

### `MF2DBuffer_LockFlags_ReadWrite:0x3`

Lock the buffer for both reading and writing.

### `MF2DBuffer_LockFlags_ForceDWORD:0x7fffffff`

Reserved. This member forces the enumeration type to compile as a **DWORD** value.

## See also

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)