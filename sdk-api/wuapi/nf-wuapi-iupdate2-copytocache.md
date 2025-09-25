# IUpdate2::CopyToCache

## Description

Copies files for an update from a specified source location to the internal Windows Update Agent (WUA) download cache.

## Parameters

### `pFiles` [in]

An [IStringCollection](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-istringcollection) interface that represents a collection of strings that contain the full paths of the files for an update.

The strings must give the full paths of the files that are being copied. The strings cannot give only the directory that contains the files.

## Return value

Returns **S_OK** if successful. Otherwise, returns a COM or Windows error code.

This method can also return the following error codes.

| Return code | Description |
| --- | --- |
| **E_ACCESSDENIED** | This method cannot be called from a remote computer. |
| **E_INVALIDARG** | A parameter value is invalid. |
| **WU_E_INVALID_OPERATION** | The computer could not access the update site. |

## Remarks

This method returns **WU_E_INVALID_OPERATION** if the object that is implementing the interface has been locked down.

**Note** We don't recommend or support the use of the [IUpdate::CopyFromCache](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdate-copyfromcache) and **IUpdate2::CopyToCache** methods to move downloaded updates from one computer to another computer. When the Windows Update Agent (WUA) downloads an update, it might only download the portions of the update’s payload that are necessary for a particular client computer. The necessary portions of the update’s payload can often vary from one computer to another computer, even if the computers have similar hardware and software configurations. **IUpdate2::CopyToCache** only works if the provided files are an exact match for the files that Windows Update would have normally downloaded on that computer; if you called **IUpdate::CopyFromCache** to obtain the files on a different computer, the files are likely not to match the files that Windows Update would have normally downloaded so **IUpdate2::CopyToCache** might fail.

## See also

[IUpdate2](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdate2)