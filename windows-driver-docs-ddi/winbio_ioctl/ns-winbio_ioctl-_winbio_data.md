# _WINBIO_DATA structure

## Description

The WINBIO_DATA structure specifies data in IOCTL payloads.

## Members

### `Size`

Specifies the size, in bytes, of the payload.

### `Data`

Specifies an array that contains the payload. Frequently this member contains a structure of type [WINBIO_BIR](https://learn.microsoft.com/windows-hardware/drivers/ddi/winbio_types/ns-winbio_types-_winbio_bir).

## Remarks

The WINBIO_DATA structure associates a length, in bytes, with an arbitrary block of contiguous memory.