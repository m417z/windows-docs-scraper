# IUpdateSession::CreateUpdateDownloader

## Description

Returns an [IUpdateDownloader](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdatedownloader) interface for this session.

## Parameters

### `retval` [out]

An [IUpdateDownloader](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdatedownloader) interface for this session.

## Return value

Returns **S_OK** if successful. Otherwise, returns a COM or Windows error code.

This method can also return the following error codes.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | A parameter value is invalid. |
| **E_ACCESSDENIED** | This method cannot be called from a remote computer. |

## Remarks

An [IUpdateDownloader](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdatedownloader) interface can also be created by using the UpdateDownloader coclass.

## See also

[IUpdateSession](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdatesession)