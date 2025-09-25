# MprConfigBufferFree function

## Description

The
**MprConfigBufferFree** function frees buffers allocated by calls to the following functions:

MprConfigXEnum

MprConfigXGetInfo

where X stands for Server,
[Interface](https://learn.microsoft.com/windows/desktop/RRAS/interface), Transport, or InterfaceTransport.

## Parameters

### `pBuffer` [in]

Pointer to a memory buffer allocated by a previous call to:

MprConfigXEnum

MprConfigXGetInfo

where X stands for Server,
[Interface](https://learn.microsoft.com/windows/desktop/RRAS/interface), Transport, or InterfaceTransport.

## Return value

If the function succeeds, the return value is NO_ERROR.

## See also

[MprConfigInterfaceEnum](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfiginterfaceenum)

[MprConfigInterfaceGetInfo](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfiginterfacegetinfo)

[MprConfigInterfaceTransportEnum](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfiginterfacetransportenum)

[MprConfigInterfaceTransportGetInfo](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfiginterfacetransportgetinfo)

[MprConfigServerGetInfo](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigservergetinfo)

[MprConfigTransportEnum](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigtransportenum)

[MprConfigTransportGetInfo](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigtransportgetinfo)

[Router Configuration Functions](https://learn.microsoft.com/windows/desktop/RRAS/router-configuration-functions)

[Router Management Reference](https://learn.microsoft.com/windows/desktop/RRAS/router-management-reference)