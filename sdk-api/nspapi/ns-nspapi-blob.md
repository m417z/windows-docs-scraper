# BLOB structure

## Description

The
**BLOB** structure, derived from Binary Large Object, contains information about a block of data.

## Members

### `cbSize`

Size of the block of data pointed to by **pBlobData**, in bytes.

### `pBlobData.size_is`

### `pBlobData.size_is.cbSize`

### `pBlobData`

Pointer to a block of data.

## Remarks

The structure name
**BLOB** comes from the acronym BLOB, which stands for Binary Large Object.

This structure does not describe the nature of the data pointed to by **pBlobData**.

**Note** Windows Sockets defines a similar
**BLOB** structure in Wtypes.h. Using both header files in the same source code file creates redefinition–compile time errors.

## See also

[Bluetooth and BLOB](https://learn.microsoft.com/windows/desktop/Bluetooth/bluetooth-and-blob)

[SERVICE_INFO](https://learn.microsoft.com/windows/desktop/api/nspapi/ns-nspapi-service_infoa)