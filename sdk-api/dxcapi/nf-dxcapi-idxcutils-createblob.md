## Description

Create a blob containing a copy of the existing data. The new blob and its contents are allocated with the current allocator.

Use this method in preference to [IDxcLibrary::CreateBlobWithEncodingOnHeapCopy](https://learn.microsoft.com/windows/win32/api/dxcapi/nf-dxcapi-idxclibrary-createblobwithencodingonheapcopy).

## Parameters

### `pData`

A pointer to a buffer containing the contents of the new blob.

### `size`

The size of the *pData* buffer, in bytes.

### `codePage`

The code page to use if the blob contains text. For binary or ANSI code page, use **DXC_CP_ACP**.

### `pBlobEncoding`

The address of the pointer that receives a pointer to the newly-created blob.

## Return value

## Remarks

## See also