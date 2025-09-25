# IUpdateSession::CreateUpdateInstaller

## Description

Returns an [IUpdateInstaller](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdateinstaller) interface for this session.

## Parameters

### `retval` [out]

An [IUpdateInstaller](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdateinstaller) interface for this session.

## Return value

Returns **S_OK** if successful. Otherwise, returns a COM or Windows error code.

This method can also return the following error codes.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | A parameter value is invalid. |
| **E_ACCESSDENIED** | This method cannot be called from a remote computer. |

## Remarks

An [IUpdateInstaller](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdateinstaller) interface can also be created by using the UpdateInstaller coclass.

## See also

[IUpdateSession](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdatesession)