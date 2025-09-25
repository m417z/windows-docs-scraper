# WFDCloseSession function

## Description

The **WFDCloseSession** function closes a session after a previously successful call to the [WFDStartOpenSession](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wfdstartopensession) function.

## Parameters

### `hSessionHandle` [in]

A session handle to a Wi-Fi Direct session. This is a session handle previously returned by the [WFDStartOpenSession](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wfdstartopensession) function.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value may be one of the following return codes.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_HANDLE** | The handle is invalid. <br><br>This error is returned if the handle specified in the *hSessionHandle* parameter was not found in the handle table. |
| **ERROR_INVALID_PARAMETER** | The parameter is incorrect. <br><br>This error is returned if the *hSessionHandle* parameter is **NULL** or not valid. |
| **ERROR_INVALID_STATE** | The group or resource is not in the correct state to perform the requested operation.<br><br>This error is returned if the Wi-Fi Direct service is disabled by group policy on a domain. |
| **RPC_STATUS** | Various error codes. |

## Remarks

The **WFDCloseSession** function is part of Wi-Fi Direct, a new feature in Windows 8 and Windows Server 2012. Wi-Fi Direct is based on the development of the Wi-Fi Peer-to-Peer Technical Specification v1.1 by the Wi-Fi Alliance (see [Wi-Fi Alliance Published Specifications](https://www.wi-fi.org/file/wi-fi-peer-to-peer-services-technical-specification-package)). The goal of the Wi-Fi Peer-to-Peer Technical Specification is to provide a solution for Wi-Fi device-to-device connectivity without the need for either a Wireless Access Point (wireless AP) to setup the connection or the use of the existing Wi-Fi adhoc (IBSS) mechanism.

The **WFDCloseSession** function queues a future work item to close the session, so disconnection may not be immediate.

Calling the **WFDCloseSession** function while a [WFDStartOpenSession](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wfdstartopensession) call is pending will not close the session.

It is the responsibility of the caller to pass the **WFDCloseSession** function a handle in the *hSessionHandle*  parameter that was returned from a successful asynchronous call to the [WFDStartOpenSession](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wfdstartopensession) function.

Calling the **WFDCloseSession** function with a handle that was valid and has become invalid will yield undefined results.

## See also

[WFDCancelOpenSession](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wfdcancelopensession)

[WFDCloseHandle](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wfdclosehandle)

[WFDOpenHandle](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wfdopenhandle)

[WFDOpenLegacySession](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wfdopenlegacysession)

[WFDStartOpenSession](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wfdstartopensession)

[WFDUpdateDeviceVisibility](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wfdupdatedevicevisibility)

[WFD_OPEN_SESSION_COMPLETE_CALLBACK](https://learn.microsoft.com/windows/desktop/api/wlanapi/nc-wlanapi-wfd_open_session_complete_callback)