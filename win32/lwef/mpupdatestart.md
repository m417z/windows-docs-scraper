# MpUpdateStart function

Starts a signature update operation.

## Parameters

*hMpHandle* \[in\]

Type: **MPHANDLE**

Handle to the malware protection manager interface. This handle is returned by the [**MpManagerOpen**](https://learn.microsoft.com/windows/win32/lwef/mpmanageropen) function.

*dwUpdateOptions* \[in\]

Type: **DWORD**

Specifies the option for the signature update operation. It can be one of the following values:

| Value | Meaning |
|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **MPUPDATE\_OPTION\_NONE** | No specific option is requested.<br> |
| **MPUPDATE\_OPTION\_ASYNC** | The update operation is to be asynchronous, where **MpUpdateStart** returns immediately after the successful initiation of the signature update. (By default the update operation is synchronous, meaning **MpUpdateStart** will return only after the signature update is finished.)<br> |
| **MPUPDATE\_OPTION\_PROGRESS** | The caller is interested in receiving signature update progress information via a callback.<br> |
| **MPUPDATE\_OPTION\_HTTP** | The signature update is performed by downloading the full signature package from the Microsoft security portal site. This can be used as a fallback option if the client is experiencing a signature download problem via Microsoft Update.<br> |
| **MPUPDATE\_OPTION\_UNC** | Performs signature update using direct download from UNC shares.<br> |
| **MPUPDATE\_OPTION\_MANAGED** | Performs signature update using the Managed Service WSUS.<br> |
| **MPUPDATE\_OPTION\_UNMANAGED** | Performs signature update using the Unmanaged Service MU/WU.<br> |

*pCallbackInfo* \[in, optional\]

Type: **PMPCALLBACK\_INFO**

A pointer to the callback information used to feed the client with signature update state changes (such as start and complete) and progress information. The [**MPCALLBACK\_DATA**](https://learn.microsoft.com/windows/win32/lwef/mpcallback-data) passed back in the callback function reports actual update state and progress-related information. The following is a list of possible callbacks:

| Value | Meaning |
|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **MPNOTIFY\_SIGUPDATE\_START** | Update operation started.<br> |
| **MPNOTIFY\_SIGUPDATE\_COMPLETE** | Update operation completed.<br> |
| **MPNOTIFY\_SIGUPDATE\_SEARCH\_START** | Search for updates started.<br> |
| **MPNOTIFY\_SIGUPDATE\_SEARCH\_COMPLETE** | Search for updates completed. Additional information is available via [**MPSIGUPDATE\_DATA**](https://learn.microsoft.com/windows/win32/lwef/mpsigupdate-data) structure.<br> |
| **MPNOTIFY\_SIGUPDATE\_DOWNLOAD\_START** | Download for update started.<br> |
| **MPNOTIFY\_SIGUPDATE\_DOWNLOAD\_PROGRESS** | Download progress information. Additional information is available via [**MPSIGUPDATE\_DATA**](https://learn.microsoft.com/windows/win32/lwef/mpsigupdate-data) structure.<br> |
| **MPNOTIFY\_SIGUPDATE\_DOWNLOAD\_COMPLETE** | Download for update complete. Additional information is available via [**MPSIGUPDATE\_DATA**](https://learn.microsoft.com/windows/win32/lwef/mpsigupdate-data) structure.<br> |
| **MPNOTIFY\_SIGUPDATE\_INSTALL\_START** | Installation of update started.<br> |
| **MPNOTIFY\_SIGUPDATE\_INSTALL\_PROGRESS** | Installation progress information. Additional information is available via [**MPSIGUPDATE\_DATA**](https://learn.microsoft.com/windows/win32/lwef/mpsigupdate-data) structure.<br> |
| **MPNOTIFY\_SIGUPDATE\_INSTALL\_COMPLETE** | Installation of update completed. Additional information is available via [**MPSIGUPDATE\_DATA**](https://learn.microsoft.com/windows/win32/lwef/mpsigupdate-data) structure.<br> |
| **MPNOTIFY\_SIGUPDATE\_REQUEST\_PROCESSED** | The antimalware service processed a signature update request. Failure or success is indicated by *hResult* in [**MPCALLBACK\_DATA**](https://learn.microsoft.com/windows/win32/lwef/mpcallback-data).<br> |
| **MPNOTIFY\_SIGUPDATE\_REBOOT\_REQUIRED** | Requires reboot to complete the update operation. Failure or success is indicated by *hResult* in [**MPCALLBACK\_DATA**](https://learn.microsoft.com/windows/win32/lwef/mpcallback-data).<br> |
| **MPNOTIFY\_INTERNAL\_FAILURE** | Signature update operation has encountered a generic failure. The *hResult* in [**MPCALLBACK\_DATA**](https://learn.microsoft.com/windows/win32/lwef/mpcallback-data) has the specific error code.<br> |

*phUpdateHandle* \[out\]

Type: **PMPHANDLE**

Returned update handle which identifies the currently initiated signature update operation. This handle can be used in subsequent function calls, such as to control the signature update operation. The handle must be closed with the [**MpHandleClose**](https://learn.microsoft.com/windows/win32/lwef/mphandleclose) function.

## Return value

Type: **HRESULT**

If the function succeeds the return value is **S\_OK**.

If the function fails then the return value is a failed **HRESULT** code. The caller can use the [**MpErrorMessageFormat**](https://learn.microsoft.com/windows/win32/lwef/mperrormessageformat) function to get a generic description of the error message.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 8 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2012 \[desktop apps only\]<br> |
| Header<br> | MpClient.h |
| DLL<br> | MpClient.dll |

## See also

[**MpErrorMessageFormat**](https://learn.microsoft.com/windows/win32/lwef/mperrormessageformat)

[**MpHandleClose**](https://learn.microsoft.com/windows/win32/lwef/mphandleclose)

[**MpManagerOpen**](https://learn.microsoft.com/windows/win32/lwef/mpmanageropen)

[**MPCALLBACK\_DATA**](https://learn.microsoft.com/windows/win32/lwef/mpcallback-data)

[**MPSIGUPDATE\_DATA**](https://learn.microsoft.com/windows/win32/lwef/mpsigupdate-data)

