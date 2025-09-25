# TapeClassZeroMemory function

## Description

The **TapeClassZeroMemory** routine fills a buffer with zeros.

## Parameters

### `Buffer` [in, out]

Pointer to the buffer that needs to be cleared.

### `BufferSize` [in]

Specifies the size of the buffer, in bytes.

## Return value

None

## Remarks

A tape miniclass driver calls **TapeClassZeroMemory** to zero a buffer in a portable way. A miniclass driver must use **TapeClassZeroMemory** to clear the TAPE_INIT_DATA_EX structure and CDBs before it uses them.

## See also

[DriverEntry of Tape Miniclass Driver](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-tape-miniclass-driver)