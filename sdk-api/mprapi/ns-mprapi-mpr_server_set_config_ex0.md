# MPR_SERVER_SET_CONFIG_EX0 structure

## Description

The **MPR_SERVER_SET_CONFIG_EX** structure is used to get or set the tunnel configuration information of a RAS server.

## Members

### `Header`

A [MPRAPI_OBJECT_HEADER](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mprapi_object_header) structure that specifies the version of the **MPR_SERVER_SET_CONFIG_EX** structure.

**Note** The **revision** member of **Header** must be **MPRAPI_MPR_SERVER_SET_CONFIG_OBJECT_REVISION_1** and **type** must be **MPRAPI_OBJECT_TYPE_MPR_SERVER_SET_CONFIG_OBJECT**.

### `setConfigForProtocols`

A value that specifies the tunnel type in **ConfigParams**. The following tunnel types are supported:

| Value | Meaning |
| --- | --- |
| **MPRAPI_SET_CONFIG_PROTOCOL_FOR_PPTP** | Point-to-Point Protocol (PPTP) |
| **MPRAPI_SET_CONFIG_PROTOCOL_FOR_L2TP** | Layer 2 Tunneling Protocol (L2TP) |
| **MPRAPI_SET_CONFIG_PROTOCOL_FOR_SSTP** | Secure Socket Tunneling Protocol (SSTP) |
| **MPRAPI_SET_CONFIG_PROTOCOL_FOR_IKEV2** | Internet Key version 2 (IKEV2) |

### `ConfigParams`

A [MPRAPI_TUNNEL_CONFIG_PARAMS](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mprapi_tunnel_config_params0) structure that contains the tunnel configuration information for the tunnel type specified in **setConfigForProtocols**.

## See also

[Router Management Reference](https://learn.microsoft.com/windows/desktop/RRAS/router-management-reference)

[Router Management Structures](https://learn.microsoft.com/windows/desktop/RRAS/router-management-structures)