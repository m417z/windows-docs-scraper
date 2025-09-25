# MPR_SERVER_0 structure

## Description

The
**MPR_SERVER_0** structure is used to retrieve information about a device.

## Members

### `fLanOnlyMode`

A **BOOL** that specifies whether the Demand Dial Manager (DDM) is running on the device. If **TRUE**, the DDM is not running on the device. Otherwise, it is **FALSE**.

### `dwUpTime`

Specifies the elapsed time, in seconds, since the device was started.

### `dwTotalPorts`

Specifies the number of ports on the device.

### `dwPortsInUse`

Specifies the number of ports currently in use on the device.

## See also

[MPR_SERVER_1](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_server_1)

[MPR_SERVER_2](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_server_2)

[MprAdminServerGetInfo](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminservergetinfo)

[MprConfigServerGetInfo](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigservergetinfo)

[Router Management Reference](https://learn.microsoft.com/windows/desktop/RRAS/router-management-reference)

[Router Management Structures](https://learn.microsoft.com/windows/desktop/RRAS/router-management-structures)