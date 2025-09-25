# WFDUpdateDeviceVisibility function

## Description

The **WFDUpdateDeviceVisibility** function updates device visibility for the Wi-Fi Direct device address for a given installed Wi-Fi Direct device node.

## Parameters

### `pDeviceAddress`

A pointer to the Wi-Fi Direct device address of the client device.

This device address must be obtained from a Device Node created as a result of the Inbox pairing experience.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value may be one of the following return codes.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | The parameter is incorrect. <br><br>This error is returned if the *pDeviceAddress* parameter is **NULL**. |
| **ERROR_NOT_ENOUGH_MEMORY** | Not enough storage is available to process this command. |
| **RPC_STATUS** | Various error codes. |

## Remarks

The **WFDUpdateDeviceVisibility** function is part of Wi-Fi Direct, a new feature in Windows 8 and Windows Server 2012. Wi-Fi Direct is based on the development of the Wi-Fi Peer-to-Peer Technical Specification v1.1 by the Wi-Fi Alliance (see [Wi-Fi Alliance Published Specifications](https://www.wi-fi.org/file/wi-fi-peer-to-peer-services-technical-specification-package)). The goal of the Wi-Fi Peer-to-Peer Technical Specification is to provide a solution for Wi-Fi device-to-device connectivity without the need for either a Wireless Access Point (wireless AP) to setup the connection or the use of the existing Wi-Fi adhoc (IBSS) mechanism.

The **WFDUpdateDeviceVisibility** function will perform a targeted Wi-Fi Direct discovery, and will update the DEVPKEY_WiFiDirect_IsVisibile property key on the device node for the given device.

## See also

[WFDCancelOpenSession](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wfdcancelopensession)

[WFDCloseHandle](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wfdclosehandle)

[WFDCloseSession](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wfdclosesession)

[WFDOpenHandle](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wfdopenhandle)

[WFDOpenLegacySession](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wfdopenlegacysession)

[WFDStartOpenSession](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wfdstartopensession)

[WFD_OPEN_SESSION_COMPLETE_CALLBACK](https://learn.microsoft.com/windows/desktop/api/wlanapi/nc-wlanapi-wfd_open_session_complete_callback)