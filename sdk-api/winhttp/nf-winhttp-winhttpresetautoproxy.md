# WinHttpResetAutoProxy function

## Description

The **WinHttpResetAutoProxy** function resets the auto-proxy.

## Parameters

### `hSession` [in]

A valid
[HINTERNET](https://learn.microsoft.com/windows/desktop/WinHttp/hinternet-handles-in-winhttp) WinHTTP session handle returned by a previous call to
the [WinHttpOpen](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpopen) function.

### `dwFlags` [in]

A set of flags that affects the reset operation.

The following flags are supported as defined in the *Winhttp.h* header file.

| Value | Meaning |
| --- | --- |
| **WINHTTP_RESET_STATE**<br><br>0x00000001 | Forces a flush and retry of non-persistent proxy information on the current network. |
| **WINHTTP_RESET_SWPAD_CURRENT_NETWORK**<br><br>0x00000002 | Flush the PAD information for the current network. |
| **WINHTTP_RESET_SWPAD_ALL**<br><br>0x00000004 | Flush the PAD information for all networks. |
| **WINHTTP_RESET_SCRIPT_CACHE**<br><br>0x00000008 | Flush the persistent HTTP cache of proxy scripts. |
| **WINHTTP_RESET_ALL**<br><br>0x0000FFFF | Forces a flush and retry of all proxy information on the current network. |
| **WINHTTP_RESET_NOTIFY_NETWORK_CHANGED**<br><br>0x00010000 | Flush the current proxy information and notify that the network changed. |
| **WINHTTP_RESET_OUT_OF_PROC**<br><br>0x00020000 | Act on the autoproxy service instead of the current process.<br><br>**Note** This flag is required.<br><br>Applications that use the [WinHttpGetProxyForUrl](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpgetproxyforurl) function to purge in-process caching should close the *hInternet* handle and open a new handle for future calls. |

## Return value

A code indicating the success or failure of the operation.

| Return code | Description |
| --- | --- |
| **ERROR_SUCCESS** | The operation was successful. |
| **ERROR_INVALID_HANDLE** | The *hSession* parameter is not a valid handle. |
| **ERROR_WINHTTP_INCORRECT_HANDLE TYPE** | The *hSession* parameter is not the product of a call to [WinHttpOpen](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpopen). |

## Remarks

To reset everything, set the *dwFlags* parameter to include **WINHTTP_RESET_ALL** and **WINHTTP_RESET_OUT_OF_PROC**.

**Note** If you make subsequent calls to the **WinHttpResetAutoProxy** function, there must be at least 30 seconds delay between calls to reset the state of the auto-proxy. If there is less than 30 seconds, the **WinHttpResetAutoProxy** function call may return **ERROR_SUCCESS** but the reset won't happen.