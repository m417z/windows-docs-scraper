# WFDOpenLegacySession function

## Description

The **WFDOpenLegacySession** function retrieves and applies a stored profile for a Wi-Fi Direct legacy device.

## Parameters

### `hClientHandle`

A **HANDLE** to the Wi-Fi Direct service for this session. This parameter is retrieved using the [WFDOpenHandle](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wfdopenhandle) function.

### `pLegacyMacAddress`

A pointer to Wi-Fi Direct device address of the legacy client device.

### `phSessionHandle`

A pointer to a **HANDLE** to receive the handle to the Wi-Fi Direct service for this session.

If the **WFDOpenLegacySession** function is successful, a handle to the Wi-Fi Direct service to use in this session is returned.

### `pGuidSessionInterface`

A pointer to the GUID of the network interface for this session.

If the **WFDOpenLegacySession** function is successful, a GUID of the network interface on which Wi-Fi Direct session is returned.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value may be one of the following return codes.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | The parameter is incorrect. <br><br>This error is returned if the *phClientHandle* or the *pLegacyMacAddress* parameter is **NULL**. |
| **ERROR_NOT_ENOUGH_MEMORY** | Not enough storage is available to process this command.<br><br>This error is returned if the system was unable to allocate memory to create the client context. |
| **RPC_STATUS** | Various error codes. |

## Remarks

The **WFDOpenLegacySession** function is part of Wi-Fi Direct, a new feature in Windows 8 and Windows Server 2012. Wi-Fi Direct is based on the development of the Wi-Fi Peer-to-Peer Technical Specification v1.1 by the Wi-Fi Alliance (see [Wi-Fi Alliance Published Specifications](https://www.wi-fi.org/file/wi-fi-peer-to-peer-services-technical-specification-package)). The goal of the Wi-Fi Peer-to-Peer Technical Specification is to provide a solution for Wi-Fi device-to-device connectivity without the need for either a Wireless Access Point (wireless AP) to setup the connection or the use of the existing Wi-Fi adhoc (IBSS) mechanism.

In order to use Wi-Fi Direct, an application must first obtain a handle to the Wi-Fi Direct service by calling the **WFDOpenLegacySession** or [WFDOpenHandle](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wfdopenhandle) function. The Wi-Fi Direct (WFD) handle returned by the **WFDOpenHandle** function is used for subsequent calls made to the Wi-Fi Direct service. The **WFDOpenLegacySession** function is used to retrieve and apply a stored profile for a Wi-Fi Direct legacy device.

The **WFDOpenLegacySession** function retrieves the stored legacy profile for device from the profile store for the specified legacy device address. This device address must be obtained from a Device Node created as a result of the Inbox pairing experience (Legacy WPS Pairing).

Once an application is done using the Wi-Fi Direct service, the application should call the [WFDCloseSession](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wfdclosesession) function to close the session and call the [WFDCloseHandle](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wfdclosehandle) function to signal to the Wi-Fi Direct service that the application is done using the service. This allows the Wi-Fi Direct service to release resources used by the application.

## See also

[WFDCancelOpenSession](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wfdcancelopensession)

[WFDCloseHandle](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wfdclosehandle)

[WFDCloseSession](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wfdclosesession)

[WFDOpenHandle](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wfdopenhandle)

[WFDStartOpenSession](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wfdstartopensession)

[WFDUpdateDeviceVisibility](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wfdupdatedevicevisibility)

[WFD_OPEN_SESSION_COMPLETE_CALLBACK](https://learn.microsoft.com/windows/desktop/api/wlanapi/nc-wlanapi-wfd_open_session_complete_callback)