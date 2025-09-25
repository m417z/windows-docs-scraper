# WFDOpenHandle function

## Description

The **WFDOpenHandle** function opens a handle to the Wi-Fi Direct service and negotiates a version of the Wi-FI Direct API to use.

## Parameters

### `dwClientVersion` [in]

The highest version of the Wi-Fi Direct API the client supports.

For Windows 8 and Windows Server 2012, this parameter should be set to **WFD_API_VERSION**, constant defined in the *Wlanapi.h* header file.

### `pdwNegotiatedVersion` [out]

A pointer to a **DWORD** to received the negotiated version.

If the **WFDOpenHandle** function is successful, the version negotiated with the Wi-Fi Direct Service to be used by this session is returned. This value is usually the highest version supported by both the client and Wi-Fi Direct service.

### `phClientHandle` [out]

A pointer to a **HANDLE** to receive the handle to the Wi-Fi Direct service for this session.

If the **WFDOpenHandle** function is successful, a handle to the Wi-Fi Direct service to use in this session is returned.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value may be one of the following return codes.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | The parameter is incorrect. <br><br>This error is returned if the *pdwNegotiatedVersion* parameter is **NULL** or the *phClientHandle* parameter is **NULL**. This value is also returned if the *dwClientVersion* parameter is not equal to **WFD_API_VERSION**. |
| **ERROR_NOT_ENOUGH_MEMORY** | Not enough storage is available to process this command.<br><br>This error is returned if the system was unable to allocate memory to create the client context. |
| **ERROR_REMOTE_SESSION_LIMIT_EXCEEDED** | An attempt was made to establish a session to a network server, but there are already too many sessions established to that server.<br><br>This error is returned if too many handles have been issued by the Wi-Fi Direct service. |
| **RPC_STATUS** | Various error codes. |

## Remarks

The **WFDOpenHandle** function is part of Wi-Fi Direct, a new feature in Windows 8 and Windows Server 2012. Wi-Fi Direct is based on the development of the Wi-Fi Peer-to-Peer Technical Specification v1.1 by the Wi-Fi Alliance (see [Wi-Fi Alliance Published Specifications](https://www.wi-fi.org/file/wi-fi-peer-to-peer-services-technical-specification-package)). The goal of the Wi-Fi Peer-to-Peer Technical Specification is to provide a solution for Wi-Fi device-to-device connectivity without the need for either a Wireless Access Point (wireless AP) to setup the connection or the use of the existing Wi-Fi adhoc (IBSS) mechanism.

In order to use Wi-Fi Direct, an application must first obtain a handle to the Wi-Fi Direct service by calling the **WFDOpenHandle** function. The Wi-Fi Direct (WFD) handle returned by the **WFDOpenHandle** function is used for subsequent calls made to the Wi-Fi Direct service. Once an application is done using the Wi-Fi Direct service, the application should call the [WFDCloseHandle](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wfdclosehandle) function to signal to the Wi-Fi Direct service that the application is done using the service. This allows the Wi-Fi Direct service to release resources used by the application.

## See also

[WFDCancelOpenSession](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wfdcancelopensession)

[WFDCloseHandle](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wfdclosehandle)

[WFDCloseSession](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wfdclosesession)

[WFDOpenLegacySession](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wfdopenlegacysession)

[WFDStartOpenSession](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wfdstartopensession)

[WFDUpdateDeviceVisibility](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wfdupdatedevicevisibility)

[WFD_OPEN_SESSION_COMPLETE_CALLBACK](https://learn.microsoft.com/windows/desktop/api/wlanapi/nc-wlanapi-wfd_open_session_complete_callback)