# WFDCloseHandle function

## Description

The **WFDCloseHandle** function closes a handle to the Wi-Fi Direct service.

## Parameters

### `hClientHandle` [in]

A client handle to the Wi-Fi Direct service. This handle was obtained by a previous call to the [WFDOpenHandle](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wfdopenhandle) function.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value may be one of the following return codes.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_HANDLE** | The handle is invalid. <br><br>This error is returned if the handle specified in the *hClientHandle* parameter was not found in the handle table. |
| **ERROR_INVALID_PARAMETER** | The parameter is incorrect. <br><br>This error is returned if the *hClientHandle* parameter is **NULL** or not valid. |
| **RPC_STATUS** | Various error codes. |

## Remarks

The **WFDCloseHandle** function is part of Wi-Fi Direct, a new feature in Windows 8 and Windows Server 2012. Wi-Fi Direct is based on the development of the Wi-Fi Peer-to-Peer Technical Specification v1.1 by the Wi-Fi Alliance (see [Wi-Fi Alliance Published Specifications](https://www.wi-fi.org/file/wi-fi-peer-to-peer-services-technical-specification-package)). The goal of the Wi-Fi Peer-to-Peer Technical Specification is to provide a solution for Wi-Fi device-to-device connectivity without the need for either a Wireless Access Point (wireless AP) to setup the connection or the use of the existing Wi-Fi adhoc (IBSS) mechanism.

In order to use Wi-Fi Direct, an application must first obtain a handle to the Wi-Fi Direct service by calling the [WFDOpenHandle](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wfdopenhandle) function. The Wi-Fi Direct (WFD) handle returned by the **WFDOpenHandle** function is used for subsequent calls made to the Wi-Fi Direct service. Once an application is done using the Wi-Fi Direct service, the application should call the **WFDCloseHandle** function to signal to the Wi-Fi Direct service that the application is done using the service. This allows the Wi-Fi Direct service to release resources used by the application.

## See also

[WFDCancelOpenSession](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wfdcancelopensession)

[WFDCloseSession](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wfdclosesession)

[WFDOpenHandle](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wfdopenhandle)

[WFDOpenLegacySession](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wfdopenlegacysession)

[WFDStartOpenSession](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wfdstartopensession)

[WFDUpdateDeviceVisibility](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wfdupdatedevicevisibility)

[WFD_OPEN_SESSION_COMPLETE_CALLBACK](https://learn.microsoft.com/windows/desktop/api/wlanapi/nc-wlanapi-wfd_open_session_complete_callback)