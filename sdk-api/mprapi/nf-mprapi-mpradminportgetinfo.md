# MprAdminPortGetInfo function

## Description

The
**MprAdminPortGetInfo** function gets information for a specific port.

## Parameters

### `hRasServer` [in]

Handle to the RAS server computer on which to collect port information. Obtain this handle by calling
[MprAdminServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminserverconnect).

### `dwLevel` [in]

A DWORD value that describes the format in which the information is returned in the *lplpbBuffer* parameter. Acceptable values for *dwLevel* include 0 and 1 as listed in the following table.

| Value | Structure Format |
| --- | --- |
| 0 | [RAS_PORT_0](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_port_0) |
| 1 | [RAS_PORT_1](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_port_1) |

### `hPort` [in]

Handle to the port for which to collect information. Obtain this handle by calling
[MprAdminPortEnum](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminportenum).

### `lplpbBuffer` [out]

On successful completion, a pointer to a structure that describes the port. These structures are of type [RAS_PORT_0](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_port_0) or [RAS_PORT_1](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_port_1) depending on the value of the *dwLevel* parameter. Free this memory by calling
[MprAdminBufferFree](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminbufferfree).

## Return value

If the function succeeds, the return value is **NO_ERROR**.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The calling application does not have sufficient privileges. |
| **ERROR_DDM_NOT_RUNNING** | The Demand Dial Manager (DDM) is not running, possibly because the Dynamic Interface Manager (DIM) is configured to run only on a LAN. |
| **ERROR_INVALID_PARAMETER** | At least one of the following parameters is **NULL** or does not point to valid memory: *lplpBuffer*, *lpdwEntriesRead*, or *lpdwTotalEntries*. |
| **ERROR_INVALID_PORT_HANDLE** | The *hPort* parameter is invalid. |
| **ERROR_NOT_SUPPORTED** | The *dwLevel* parameter is not zero. |
| **Other** | An error from MprError.h, RasError.h, or WinError.h. |

## Remarks

This function is available on Windows NT 4.0 if the RRAS redistributable is installed. However, the version of Mprapi.dll that ships with the RRAS redistributable exports the function as
**RasAdminPortGetInfo** rather than
**MprAdminPortGetInfo**. Therefore, when using the RRAS redistributable, use
[LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and
[GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) to access this function.

## See also

[MprAdminBufferFree](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminbufferfree)

[MprAdminPortEnum](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminportenum)

[MprAdminServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminserverconnect)

[RAS Administration Functions](https://learn.microsoft.com/windows/desktop/RRAS/ras-administration-functions)

[Remote Access Service Administration Reference](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-administration-reference)