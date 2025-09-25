## Description

Create a blob with data loaded from a file. The new blob and its contents are allocated with the current allocator.

Use this method in preference to [IDxcLibrary::CreateBlobFromFile](https://learn.microsoft.com/windows/win32/api/dxcapi/nf-dxcapi-idxclibrary-createblobfromfile).

## Parameters

### `pFileName`

The name of the file to load from.

### `pCodePage`

An optional code page to use if the blob contains text. For binary data, pass **NULL**.

### `pBlobEncoding`

The address of the pointer that receives a pointer to the newly-created blob.

## Return value

## Remarks

## See also