## Description

The **WINHTTP_ASYNC_RESULT** structure contains the result of a call to an asynchronous function. This structure is used with the
[WINHTTP_STATUS_CALLBACK](https://learn.microsoft.com/windows/desktop/api/winhttp/nc-winhttp-winhttp_status_callback) prototype.

## Members

### `dwResult`

Return value from an asynchronous Microsoft Windows HTTP Services (WinHTTP) function. This member can be one of the following values:

| Value | Meaning |
| --- | --- |
| **API_RECEIVE_RESPONSE**<br><br>1 | The error occurred during a call to [WinHttpReceiveResponse](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpreceiveresponse). |
| **API_QUERY_DATA_AVAILABLE**<br><br>2 | The error occurred during a call to [WinHttpQueryDataAvailable](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpquerydataavailable). |
| **API_READ_DATA**<br><br>3 | The error occurred during a call to [WinHttpReadData](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpreaddata). |
| **API_WRITE_DATA**<br><br>4 | The error occurred during a call to [WinHttpWriteData](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpwritedata). |
| **API_SEND_REQUEST**<br><br>5 | The error occurred during a call to [WinHttpSendRequest](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpsendrequest). |
| **API_GET_PROXY_FOR_URL**<br><br>6 | The error occurred during a call to [WinHttpGetProxyForUrlEx](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpgetproxyforurlex). |

### `dwError`

Contains the error code if
**dwResult** indicates that the function failed.

## Remarks

**Note** For Windows XP and Windows 2000, see the [Run-Time Requirements](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page) section of the WinHttp start page.

## See also

[WinHTTP
Versions](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-versions)