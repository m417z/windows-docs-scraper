# RasGetSubEntryHandleW function

## Description

The
**RasGetSubEntryHandle** function retrieves a connection handle for a specified subentry of a multilink connection.

## Parameters

### `unnamedParam1` [in]

Specifies the **HRASCONN** connection handle returned by the
[RasDial](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasdiala) function for a multilink phone-book entry.

### `unnamedParam2` [in]

Specifies a valid subentry index for the phone-book entry.

### `unnamedParam3` [out]

Pointer to the **HRASCONN** variable that receives a connection handle that represents the subentry connection.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

If the function fails, the return value is one of the following error codes or a value from [Routing and Remote Access Error Codes](https://learn.microsoft.com/windows/desktop/RRAS/routing-and-remote-access-error-codes) or Winerror.h.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_HANDLE** | The *hRasConn* connection handle does not represent a connected phone-book entry. |
| **ERROR_PORT_NOT_OPEN** | The *hRasConn* and *dwSubEntry* parameters are valid, but the specified subentry is not connected. |
| **ERROR_NO_MORE_ITEMS** | The value specified by *dwSubEntry* exceeds the maximum number of subentries for the phone-book entry. |

## Remarks

The connection handle specified in the *hRasConn* parameter refers to the entire multilink connection, but the connection handle returned in the **lphRasConn* parameter refers only to the subentry connection. Use the subentry connection handle in any function that accepts an *hRasConn* parameter, including the
[RasHangUp](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rashangupa),
[RasGetConnectStatus](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasgetconnectstatusa), and
[RasGetProjectionInfoEx](https://learn.microsoft.com/windows/win32/api/ras/nf-ras-rasgetprojectioninfoex) functions. The projection information returned by
**RasGetProjectionInfo** for a multilink entry is the same for the each of the subentry connection handles as it is for the main connection handle.

You can call
[RasHangUp](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rashangupa) on the handle returned by
**RasGetSubEntryHandle** to terminate a single link in a multi-link connection. However, you cannot use
[RasGetConnectStatus](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasgetconnectstatusa) to determine if the link terminated;
**RasGetConnectStatus** may not return ERROR_INVALID_HANDLE even though the link terminated successfully.

> [!NOTE]
> The ras.h header defines RasGetSubEntryHandle as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RasDial](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasdiala)

[RasGetConnectStatus](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasgetconnectstatusa)

[RasGetProjectionInfoEx](https://learn.microsoft.com/windows/win32/api/ras/nf-ras-rasgetprojectioninfoex)

[RasHangUp](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rashangupa)

[Remote Access Service (RAS) Overview](https://learn.microsoft.com/windows/desktop/RRAS/about-remote-access-service)

[Remote Access Service Functions](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-functions)