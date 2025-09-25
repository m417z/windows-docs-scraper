# WFDCancelOpenSession function

## Description

The **WFDCancelOpenSession** function indicates that the application wants to cancel a pending [WFDStartOpenSession](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wfdstartopensession) function that has not completed.

## Parameters

### `hSessionHandle` [in]

A session handle to a Wi-Fi Direct session to cancel. This is a session handle previously returned by the [WFDStartOpenSession](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wfdstartopensession) function.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value may be one of the following return codes.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_HANDLE** | The handle is invalid. <br><br>This error is returned if the handle specified in the *hSessionHandle* parameter was not found in the handle table. |
| **ERROR_INVALID_PARAMETER** | The parameter is incorrect. <br><br>This error is returned if the *hSessionHandle* parameter is **NULL** or not valid. |
| **RPC_STATUS** | Various error codes. |

## Remarks

The **WFDCancelOpenSession** function is part of Wi-Fi Direct, a new feature in Windows 8 and Windows Server 2012. Wi-Fi Direct is based on the development of the Wi-Fi Peer-to-Peer Technical Specification v1.1 by the Wi-Fi Alliance (see [Wi-Fi Alliance Published Specifications](https://www.wi-fi.org/file/wi-fi-peer-to-peer-services-technical-specification-package)). The goal of the Wi-Fi Peer-to-Peer Technical Specification is to provide a solution for Wi-Fi device-to-device connectivity without the need for either a Wireless Access Point (wireless AP) to setup the connection or the use of the existing Wi-Fi adhoc (IBSS) mechanism.

A call to the **WFDCancelOpenSession** function notifies the Wi-Fi Direct service that the client requests a cancellation of this session. The **WFDCancelOpenSession** function does not modify the expected [WFDStartOpenSession](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wfdstartopensession) behavior. The callback function specified to the **WFDStartOpenSession** function will still be called, and the **WFDStartOpenSession** function may not be completed immediately.

It is the responsibility of the caller to pass the **WFDCancelOpenSession** function a handle in the *hSessionHandle*  parameter that was returned from call to the [WFDStartOpenSession](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wfdstartopensession) function.

## See also

[WFDCloseHandle](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wfdclosehandle)

[WFDCloseSession](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wfdclosesession)

[WFDOpenHandle](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wfdopenhandle)

[WFDOpenLegacySession](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wfdopenlegacysession)

[WFDStartOpenSession](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wfdstartopensession)

[WFDUpdateDeviceVisibility](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wfdupdatedevicevisibility)

[WFD_OPEN_SESSION_COMPLETE_CALLBACK](https://learn.microsoft.com/windows/desktop/api/wlanapi/nc-wlanapi-wfd_open_session_complete_callback)