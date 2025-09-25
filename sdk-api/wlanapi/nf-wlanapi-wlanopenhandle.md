# WlanOpenHandle function

## Description

The **WlanOpenHandle** function opens a connection to the server.

## Parameters

### `dwClientVersion` [in]

The highest version of the WLAN API that the client supports.

| Value | Meaning |
| --- | --- |
| 1 | Client version for Windows XP with SP3 and Wireless LAN API for Windows XP with SP2. |
| 2 | Client version for Windows Vista and Windows Server 2008 |

### `pReserved`

Reserved for future use. Must be set to **NULL**.

### `pdwNegotiatedVersion` [out]

The version of the WLAN API that will be used in this session. This value is usually the highest version supported by both the client and server.

### `phClientHandle` [out]

A handle for the client to use in this session. This handle is used by other functions throughout the session.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value may be one of the following return codes.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | *pdwNegotiatedVersion* is **NULL**, *phClientHandle* is **NULL**, or *pReserved* is not **NULL**. |
| **ERROR_NOT_ENOUGH_MEMORY** | Failed to allocate memory to create the client context. |
| **RPC_STATUS** | Various error codes. |
| **ERROR_REMOTE_SESSION_LIMIT_EXCEEDED** | Too many handles have been issued by the server. |

## Remarks

The version number specified by *dwClientVersion* and *pdwNegotiatedVersion* is a composite version number made up of both major and minor versions. The major version is specified by the low-order word, and the minor version is specified by the high-order word. The macros `WLAN_API_VERSION_MAJOR(_v)` and `WLAN_API_VERSION_MINOR(_v)` return the major and minor version numbers respectively. You can construct a version number using the macro `WLAN_API_MAKE_VERSION(_major, _minor)`.

**Windows XP with SP3 and Wireless LAN API for Windows XP with SP2:** **WlanOpenHandle** will return an error message if the Wireless Zero Configuration (WZC) service has not been started or if the WZC service is not responsive.

## See also

[WlanCloseHandle](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanclosehandle)