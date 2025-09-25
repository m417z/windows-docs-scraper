# IAppxBlockMapFile::GetName

## Description

Retrieves the name of the associated zip file item.

## Parameters

### `name` [out, retval]

Type: **[LPWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

In a valid app package, *name* corresponds to the name of the associated zip file item.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The caller is responsible for deallocating the memory used for *name*. Use the [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function to deallocate the memory.

## See also

[IAppxBlockMapFile](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxblockmapfile)