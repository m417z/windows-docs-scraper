# IAppxFile::GetName

## Description

Retrieves the name of the file, including its path relative to the package root directory.

## Parameters

### `fileName` [out, retval]

Type: **[LPWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

A string that contains the name and relative path of the file.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The string returned in *fileName* is identical to the file name listed in the block map.

The caller is responsible for deallocating the memory used by *fileName*. Use the [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function to deallocate the string's memory.

#### Examples

For an example, see [Quickstart: Extract app package contents](https://learn.microsoft.com/windows/desktop/appxpkg/how-to-extract-content-from-a-package).

## See also

[IAppxFile](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxfile)