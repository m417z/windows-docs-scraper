# IUpdateSession::CreateUpdateSearcher

## Description

Returns an [IUpdateSearcher](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdatesearcher) interface for this session.

## Parameters

### `retval` [out]

An [IUpdateSearcher](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdatesearcher) interface for this session.

## Return value

Returns **S_OK** if successful. Otherwise, a COM or Windows error code.

This method can also return the following error codes.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | A parameter value is invalid. |

## Remarks

An [IUpdateSearcher](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdatesearcher) interface can also be created by using the UpdateSearcher coclass.

## See also

[IUpdateSession](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdatesession)