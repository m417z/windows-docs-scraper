# IUpdate::CopyFromCache

## Description

Copies the contents of an update to a specified path.

## Parameters

### `path` [in]

The path of the location where the update contents are to be copied.

### `toExtractCabFiles` [in]

Reserved for future use.

You must set *toExtractCabFiles* to **VARIANT_TRUE** or **VARIANT_FALSE**.

## Return value

Returns **S_OK** if successful. Otherwise, returns a COM or Windows error code.

This method can also return the following error codes.

| Return code | Description |
| --- | --- |
| **E_ACCESSDENIED** | This method cannot be called from a remote computer. |
| **E_INVALIDARG** | A parameter value is invalid. |
| **WU_E_INVALID_OPERATION** | The computer could not access the update site.<br><br>(This method returns **WU_E_INVALID_OPERATION** if the object that is implementing the interface has been locked down.) |
| **WU_E_EULAS_DECLINED** | The Microsoft Software License Terms are not accepted. |
| **WU_E_DM_NOTDOWNLOADED** | The files are not downloaded. |
| **WU_E_DM_INCORRECTFILEHASH** | The file hash verification failed. |
| **COR_E_DIRECTORYNOTFOUND** | A file or directory could not be located. |
| **STG_E_PATHNOTFOUND** | A file or directory could not be located. |

## Remarks

 To copy bundled updates, call this method on the individual updates that are bundled in this update.

**Note** We don't recommend or support the use of the **IUpdate::CopyFromCache** and [IUpdate2::CopyToCache](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdate2-copytocache) methods to move downloaded updates from one computer to another computer. When the Windows Update Agent (WUA) downloads an update, it might only download the portions of the update’s payload that are necessary for a particular client computer. The necessary portions of the update’s payload can often vary from one computer to another computer, even if the computers have similar hardware and software configurations. **IUpdate2::CopyToCache** only works if the provided files are an exact match for the files that Windows Update would have normally downloaded on that computer; if you called **IUpdate::CopyFromCache** to obtain the files on a different computer, the files are likely not to match the files that Windows Update would have normally downloaded so **IUpdate2::CopyToCache** might fail.

## See also

[IUpdate](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdate)