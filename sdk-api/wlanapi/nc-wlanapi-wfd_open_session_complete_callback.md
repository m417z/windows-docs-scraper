# WFD_OPEN_SESSION_COMPLETE_CALLBACK callback function

## Description

The **WFD_OPEN_SESSION_COMPLETE_CALLBACK** function defines the callback function that is called by the [WFDStartOpenSession](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wfdstartopensession) function when the **WFDStartOpenSession** operation completes.

## Parameters

### `hSessionHandle` [in]

A session handle to a Wi-Fi Direct session. This is a session handle previously returned by the [WFDStartOpenSession](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wfdstartopensession) function.

### `pvContext` [in]

An context pointer passed to the callback function from the [WFDStartOpenSession](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wfdstartopensession) function.

### `guidSessionInterface` [in]

The interface GUID of the local network interface on which this Wi-Fi Direct device has an open session.
This parameter is useful if higher-layer protocols need to determine which network interface a Wi-Fi Direct session is bound to.
This value is only returned if the *dwError* parameter is ERROR_SUCCESS.

### `dwError` [in]

A value that specifies whether there was an error encountered during the call to the [WFDStartOpenSession](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wfdstartopensession) function. If this value is ERROR_SUCCESS, then no error occurred and the operation to open the session completed successfully.

The following other values are possible:

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | The parameter is incorrect. This error is returned if the *hClientHandle* parameter is **NULL** or not valid. |
| **ERROR_INVALID_STATE** | The group or resource is not in the correct state to perform the requested operation. This error is returned if the Wi-Fi Direct service is disabled by group policy on a domain. |
| **ERROR_SERVICE_NOT_ACTIVE** | The service has not been started. This error is returned if the WLAN AutoConfig Service is not running. |
| **RPC_STATUS** | Various RPC and other error codes. Use **FormatMessage** to obtain the message string for the returned error. |

### `dwReasonCode` [in]

A value that specifies the more detail if an error occurred during [WFDStartOpenSession](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wfdstartopensession).

## Remarks

The **WFD_OPEN_SESSION_COMPLETE_CALLBACK** function is part of Wi-Fi Direct, a new feature in Windows 8 and Windows Server 2012. Wi-Fi Direct is based on the development of the Wi-Fi Peer-to-Peer Technical Specification v1.1 by the Wi-Fi Alliance (see [Wi-Fi Alliance Published Specifications](https://www.wi-fi.org/file/wi-fi-peer-to-peer-services-technical-specification-package)). The goal of the Wi-Fi Peer-to-Peer Technical Specification is to provide a solution for Wi-Fi device-to-device connectivity without the need for either a Wireless Access Point (wireless AP) to setup the connection or the use of the existing Wi-Fi adhoc (IBSS) mechanism.

The [WFDStartOpenSession](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wfdstartopensession) function starts an asynchronous operation to start an on-demand connection to a specific Wi-Fi Direct device. The target Wi-Fi device must previously have been paired through the Windows Pairing experience. When the asynchronous operation to make the Wi-FI Direct connection completes, the callback function specified in the *pfnCallback* parameter is called.

## See also

[WFDCancelOpenSession](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wfdcancelopensession)

[WFDCloseHandle](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wfdclosehandle)

[WFDCloseSession](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wfdclosesession)

[WFDOpenHandle](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wfdopenhandle)

[WFDStartOpenSession](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wfdstartopensession)

[WFD_OPEN_SESSION_COMPLETE_CALLBACK](https://learn.microsoft.com/windows/desktop/api/wlanapi/nc-wlanapi-wfd_open_session_complete_callback)