# MprAdminBufferFree function

## Description

The
**MprAdminBufferFree** function frees memory buffers returned by:
[MprAdminDeviceEnum](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmindeviceenum), [MprAdminInterfaceGetInfo](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfacegetinfo),
[MprAdminInterfaceDeviceGetInfo](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfacedevicegetinfo), [MprAdminInterfaceEnum](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfaceenum),
[MprAdminServerGetInfo](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminservergetinfo),
[MprAdminInterfaceTransportGetInfo](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfacetransportgetinfo), and
[MprAdminTransportGetInfo](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmintransportgetinfo).

## Parameters

### `pBuffer` [in]

Pointer to the memory buffer to free.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is the following error code.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | The *pBuffer* parameter is **NULL**. |

## See also

[MprAdminInterfaceEnum](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfaceenum)

[MprAdminInterfaceGetInfo](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfacegetinfo)

[MprAdminInterfaceTransportGetInfo](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfacetransportgetinfo)

[MprAdminServerGetInfo](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminservergetinfo)

[MprAdminTransportGetInfo](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmintransportgetinfo)

[Router Administration Functions](https://learn.microsoft.com/windows/desktop/RRAS/router-administration-functions)

[Router Management Reference](https://learn.microsoft.com/windows/desktop/RRAS/router-management-reference)