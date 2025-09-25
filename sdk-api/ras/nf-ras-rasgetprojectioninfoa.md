# RasGetProjectionInfoA function

## Description

The
**RasGetProjectionInfo** function obtains information about a remote access projection operation for a specified remote access component protocol.

## Parameters

### `unnamedParam1` [in]

Handle to the remote access connection of interest. An application obtains a RAS connection handle from the
[RasDial](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasdiala) or
[RasEnumConnections](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasenumconnectionsa) function.

### `unnamedParam2` [in]

Specifies the
[RASPROJECTION](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377648(v=vs.85)) enumerated type value that identifies the protocol of interest.

### `unnamedParam3` [out]

Pointer to a buffer that receives the information specified by the *rasprojection* parameter. The information is in a structure appropriate to the *rasprojection* value.

| rasprojection value | Meaning |
| --- | --- |
| **RASP_Amb** | [RASAMB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa376720(v=vs.85))<br><br>**Note** Supported on Windows 2000 or earlier. |
| **RASP_PppCcp** | [RASPPPCCP](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377620(v=vs.85))<br><br>**Note** Supported on Windows 2000 or later. |
| **RASP_PppIp** | [RASPPPIP](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377634(v=vs.85)) |
| **RASP_PppIpv6** | [RASPPPIPV6](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa816540(v=vs.85))<br><br>**Note** Supported on Windows Vista or later. |
| **RASP_PppIpx** | [RASPPPIPX](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377623(v=vs.85))<br><br>**Note** Not supported on 64-bit Microsoft Windows. |
| **RASP_PppLcp** | [RASPPPLCP](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377638(v=vs.85))<br><br>**Note** Supported on Windows 2000 or later. |
| **RASP_PppNbf** | [RASPPPNBF](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377642(v=vs.85))<br><br>**Note** Supported on Windows 2000 or earlier. |
| **RASP_Slip** | [RASPSLIP](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377836(v=vs.85))<br><br>**Note** Supported on Windows Server 2003 or earlier. |

### `unnamedParam4` [in, out]

Pointer to a variable that, on input, specifies the size, in bytes, of the buffer pointed to by *lpprojection*.

On output, this variable receives the size, in bytes, of the *lpprojection* buffer.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

If the function fails, the return value is one of the following error codes or a value from [Routing and Remote Access Error Codes](https://learn.microsoft.com/windows/desktop/RRAS/routing-and-remote-access-error-codes) or Winerror.h.

| Value | Meaning |
| --- | --- |
| **ERROR_BUFFER_TOO_SMALL** | The buffer pointed to by *lpprojection* is not large enough to contain the requested information. |
| **ERROR_INVALID_HANDLE** | The *hrasconn* parameter is not a valid handle. |
| **ERROR_INVALID_PARAMETER** | One of the parameters is invalid. |
| **ERROR_INVALID_SIZE** | The **dwSize** member of the structure pointed to by *lpprojection* specifies an invalid size. |
| **ERROR_PROTOCOL_NOT_CONFIGURED** | The control protocol for which information was requested neither succeeded nor failed, because the connection's phone-book entry did not require that an attempt to negotiate the protocol be made. This is a RAS error code. |

## Remarks

Remote access projection is the process whereby a remote access server and a remote client negotiate network protocol-specific information. A remote access server uses this network protocol-specific information to represent a remote client on the network.

Remote access projection information is not available until the operating system has executed the
[RasDial](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasdiala)
[RASCS_Projected](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa376727(v=vs.85)) state on the remote access connection. If
**RasGetProjectionInfo** is called prior to the **RASCS_Projected** state, it returns **ERROR_PROJECTION_NOT_COMPLETE**.

The NetBEUI protocol and authentication message blocks (AMB) are only supported on Windows 2000 and earlier versions of Windows.

> [!NOTE]
> The ras.h header defines RasGetProjectionInfo as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RASAMB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa376720(v=vs.85))

[RASPPPCCP](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377620(v=vs.85))

[RASPPPIP](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377634(v=vs.85))

[RASPPPIPV6](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa816540(v=vs.85))

[RASPPPIPX](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377623(v=vs.85))

[RASPPPLCP](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377638(v=vs.85))

[RASPPPNBF](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377642(v=vs.85))

[RASPROJECTION](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377648(v=vs.85))

[RASPSLIP](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377836(v=vs.85))

[RasDial](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasdiala)

[RasEnumConnections](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasenumconnectionsa)

[Remote Access Service (RAS) Overview](https://learn.microsoft.com/windows/desktop/RRAS/about-remote-access-service)

[Remote Access Service Functions](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-functions)