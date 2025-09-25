# IAppxFile::GetContentType

## Description

Retrieves the content type of the file.

## Parameters

### `contentType` [out, retval]

Type: **[LPWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

The content type of the file.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The caller is responsible for deallocating the memory used by *contentType*. Use the [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function to deallocate the string's memory.

#### Examples

For an example, see [Quickstart: Extract app package contents](https://learn.microsoft.com/windows/desktop/appxpkg/how-to-extract-content-from-a-package).

## See also

[IAppxFile](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxfile)