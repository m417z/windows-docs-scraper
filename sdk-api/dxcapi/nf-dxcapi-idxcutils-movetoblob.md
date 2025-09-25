## Description

Create a blob, taking ownership of the memory that's allocated by the supplied allocator.

Use this method in preference to [IDxcLibrary::CreateBlobWithEncodingOnMalloc](https://learn.microsoft.com/windows/win32/api/dxcapi/nf-dxcapi-idxclibrary-createblobwithencodingonmalloc).

## Parameters

### `pData`

A pointer to a buffer containing the contents of the new blob.

### `pIMalloc`

The memory allocator to use.

### `size`

The size of the *pData* buffer, in bytes.

### `codePage`

The code page to use if the blob contains text. For binary or ANSI code page, use **DXC_CP_ACP**.

### `pBlobEncoding`

The address of the pointer that receives a pointer to the newly-created blob.

## Return value

## Remarks

## See also