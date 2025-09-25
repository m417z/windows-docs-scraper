# MPR_SERVER_EX0 structure

## Description

The **MPR_SERVER_EX** structure is used to get or set the configuration of a RAS server.

## Members

### `Header`

A [MPRAPI_OBJECT_HEADER](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mprapi_object_header) structure that specifies the version of the **MPR_SERVER_EX** structure.

**Note** The **revision** member of **Header** must be **MPRAPI_MPR_SERVER_OBJECT_REVISION_1** and **type** must be **MPRAPI_OBJECT_TYPE_MPR_SERVER_OBJECT**.

### `fLanOnlyMode`

A BOOL that is **TRUE** if the RRAS server is running in LAN-only mode and **FALSE** if it is functioning as a router.

### `dwUpTime`

A value that specifies the elapsed time, in seconds, since the RAS server was started.

### `dwTotalPorts`

A value that specifies the number of ports on the RAS server.

### `dwPortsInUse`

A value that specifies the number of ports currently in use on the RAS server.

### `Reserved`

Reserved. This value must be zero.

### `ConfigParams`

A [MPRAPI_TUNNEL_CONFIG_PARAMS](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mprapi_tunnel_config_params0) structure that contains Point-to-Point (PPTP), Secure Socket Tunneling Protocol (SSTP), Layer 2 Tunneling Protocol (L2TP), and Internet Key version 2 (IKEv2) tunnel configuration information for the RAS server.

## See also

[Router Management Reference](https://learn.microsoft.com/windows/desktop/RRAS/router-management-reference)

[Router Management Structures](https://learn.microsoft.com/windows/desktop/RRAS/router-management-structures)