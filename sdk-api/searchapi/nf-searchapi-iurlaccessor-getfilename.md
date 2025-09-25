# IUrlAccessor::GetFileName

## Description

Retrieves the file name of the item, which the filter host uses for indexing. If the item does not exist in a file system and the [IUrlAccessor::BindToStream](https://learn.microsoft.com/windows/desktop/api/searchapi/nf-searchapi-iurlaccessor-bindtostream) method is implemented, this method returns the shell's System.ParsingPath property for the item.

## Parameters

### `wszFileName` [out]

Type: **WCHAR[]**

Receives the file name as a null-terminated Unicode string.

### `dwSize` [in]

Type: **DWORD**

Size in
**TCHAR****s** of
*wszFileName*, not including the terminating **NULL**.

### `pdwLength` [out]

Type: **DWORD***

Receives a pointer to the number of
**TCHAR****s** written to **wszFileName**, not including
**NULL**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If this method is implemented, the filter host uses the file name to determine the correct [IFilter](https://learn.microsoft.com/windows/desktop/api/filter/nn-filter-ifilter) to use to parse the content of the stream returned by [IUrlAccessor::BindToStream](https://learn.microsoft.com/windows/desktop/api/searchapi/nf-searchapi-iurlaccessor-bindtostream).