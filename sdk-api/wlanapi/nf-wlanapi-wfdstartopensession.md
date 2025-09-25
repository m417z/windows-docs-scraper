# WFDStartOpenSession function

## Description

The **WFDStartOpenSession** function starts an on-demand connection to a specific Wi-Fi Direct device, which has been previously paired through the Windows Pairing experience.

## Parameters

### `hClientHandle` [in]

A client handle to the Wi-Fi Direct service. This handle was obtained by a previous call to the [WFDOpenHandle](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wfdopenhandle) function.

### `pDeviceAddress` [in]

A pointer to the target device’s Wi-Fi Direct device address. This is the MAC address of the target Wi-Fi device.

### `pvContext` [in, optional]

An optional context pointer which is passed to the callback function specified in the *pfnCallback* parameter.

### `pfnCallback` [in]

A pointer to the callback function to be called once the **WFDStartOpenSession** request has completed.

### `phSessionHandle` [out]

A handle to this specific Wi-Fi Direct session.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value may be one of the following return codes.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_HANDLE** | The handle is invalid. <br><br>This error is returned if the handle specified in the *hClientHandle* parameter was not found in the handle table. |
| **ERROR_INVALID_PARAMETER** | The parameter is incorrect. <br><br>This error is returned if the *hClientHandle* parameter is **NULL** or not valid. This error is also returned if the *pDeviceAddress* parameter is **NULL**, the *pfnCallback* parameter is **NULL**, or the *phSessionHandle* parameter is **NULL**. This value is also returned if the *dwClientVersion* parameter is not equal to **WFD_API_VERSION**. |
| **ERROR_INVALID_STATE** | The group or resource is not in the correct state to perform the requested operation.<br><br>This error is returned if the Wi-Fi Direct service is disabled by group policy on a domain. |
| **ERROR_SERVICE_NOT_ACTIVE** | The service has not been started.<br><br>This error is returned if the WLAN AutoConfig Service is not running. |
| **RPC_STATUS** | Various error codes. |

## Remarks

The **WFDStartOpenSession** function is part of Wi-Fi Direct, a new feature in Windows 8 and Windows Server 2012. Wi-Fi Direct is based on the development of the Wi-Fi Peer-to-Peer Technical Specification v1.1 by the Wi-Fi Alliance (see [Wi-Fi Alliance Published Specifications](https://www.wi-fi.org/file/wi-fi-peer-to-peer-services-technical-specification-package)). The goal of the Wi-Fi Peer-to-Peer Technical Specification is to provide a solution for Wi-Fi device-to-device connectivity without the need for either a Wireless Access Point (wireless AP) to setup the connection or the use of the existing Wi-Fi adhoc (IBSS) mechanism.

The **WFDStartOpenSession** function starts an asynchronous operation to start an on-demand connection to a specific Wi-Fi Direct device. The target Wi-Fi device must previously have been paired through the Windows Pairing experience. When the asynchronous operation completes, the callback function specified in the *pfnCallback* parameter is called.

If the application attempts to close the handle to the Wi-Fi Direct service by calling the [WFDCloseHandle](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wfdclosehandle) function before the **WFDStartOpenSession** function completes asynchronously, the **WFDCloseHandle** function will wait until the **WFDStartOpenSession** call is completed.

## See also

[WFDCancelOpenSession](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wfdcancelopensession)

[WFDCloseHandle](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wfdclosehandle)

[WFDCloseSession](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wfdclosesession)

[WFDOpenHandle](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wfdopenhandle)

[WFDOpenLegacySession](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wfdopenlegacysession)

[WFDUpdateDeviceVisibility](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wfdupdatedevicevisibility)

[WFD_OPEN_SESSION_COMPLETE_CALLBACK](https://learn.microsoft.com/windows/desktop/api/wlanapi/nc-wlanapi-wfd_open_session_complete_callback)