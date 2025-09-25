## Description

Creates a blob referencing existing memory, with no copy. You must manage the memory lifetime separately.

Use this method in preference to [IDxcLibrary::CreateBlobWithEncodingFromPinned](https://learn.microsoft.com/windows/win32/api/dxcapi/nf-dxcapi-idxclibrary-createblobwithencodingfrompinned).

## Parameters

### `pData`

Pointer to a buffer containing the contents of the new blob.

### `size`

The size of the pData buffer, in bytes.

### `codePage`

The code page to use if the blob contains text. For binary or ANSI code page, use **DXC_CP_ACP**.

### `pBlobEncoding`

Address of the pointer that receives a pointer to the newly-created blob.

## Return value

## Remarks

## See also