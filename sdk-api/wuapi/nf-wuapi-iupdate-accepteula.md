# IUpdate::AcceptEula

## Description

Accepts the Microsoft Software License Terms that are associated with Windows Update. Administrators and power users can call this method.

## Return value

Returns **S_OK** if successful. Otherwise, returns a COM or Windows error code.

This method can also return the following error codes.

| Return code | Description |
| --- | --- |
| **E_ACCESSDENIED** | This method cannot be called from a remote computer. |
| **WU_E_INVALID_OPERATION** | The computer could not access the update site.<br><br>(This method returns **WU_E_INVALID_OPERATION** if the object that is implementing the interface has been locked down.) |
| **WU_E_EULA_UNAVAILABLE** | The Microsoft Software License Terms for the update could not be located. |

## See also

[IUpdate](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdate)