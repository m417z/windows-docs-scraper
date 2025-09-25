# IDWriteRemoteFontFileStream::BeginDownload

## Description

Begins downloading all or part of the font file.

## Parameters

### `downloadOperationID` [in]

Type: **UUID**

### `fileFragments` [in]

Type: **[DWRITE_FILE_FRAGMENT](https://learn.microsoft.com/windows/win32/api/dwrite_3/ns-dwrite_3-dwrite_file_fragment)**

Array of structures, each specifying a byte range to download.

### `fragmentCount`

Type: **UINT32**

Number of elements in the fileFragments array. This can be zero to just download file information, such as the size.

### `asyncResult`

Type: **_COM_Outptr_result_maybenull_**

Receives an object that can be used to wait for the asynchronous download to complete and to get the download result upon
completion. The result may be NULL if the download completes synchronously. For example, this can happen if method determines that the requested data
is already local.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns an HRESULT success or error code.

## See also

[IDWriteRemoteFontFileStream](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwriteremotefontfilestream)