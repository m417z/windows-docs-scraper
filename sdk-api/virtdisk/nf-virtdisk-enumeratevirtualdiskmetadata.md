# EnumerateVirtualDiskMetadata function

## Description

Enumerates the metadata associated with a virtual disk.

## Parameters

### `VirtualDiskHandle` [in]

Handle to an open virtual disk.

### `NumberOfItems` [in, out]

Address of a **ULONG**. On input, the value indicates the number of elements in
the buffer pointed to by the *Items* parameter. On output, the value contains the number
of items retrieved. If the buffer was too small, the API will fail and return
**ERROR_INSUFFICIENT_BUFFER** and the **ULONG** will contain the
required buffer size.

### `Items` [out]

Address of a buffer to be filled with the **GUID**s representing the metadata. The
[GetVirtualDiskMetadata](https://learn.microsoft.com/windows/desktop/api/virtdisk/nf-virtdisk-getvirtualdiskmetadata) function can be used
to retrieve the data represented by each **GUID**.

## Return value

Status of the request.

If the function succeeds, the return value is **ERROR_SUCCESS**.

If the buffer pointed to by the *Items* parameter was too small, the return value is
**ERROR_INSUFFICIENT_BUFFER**.

If the function fails, the return value is an error code. For more information, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## See also

[VHD Functions](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd323699(v=vs.85))