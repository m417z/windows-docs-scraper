# IPrintReadStream::ReadBytes

## Description

The `ReadBytes` method reads a number of bytes into a buffer.

## Parameters

### `pvBuffer` [out]

A pointer to the buffer that the bytes will be read into..

### `cbRequested` [in]

The number of bytes that are requested for the read.

### `pcbRead` [out]

A pointer to the number of bytes actually read.

### `pbEndOfFile` [out]

A pointer to a **BOOL** value that indicates whether the end of file (EOF) was read.

## Return value

`ReadBytes` returns an **HRESULT** value.