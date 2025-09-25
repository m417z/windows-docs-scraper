# IKEV2_CONFIG_PARAMS structure

## Description

The **IKEV2_CONFIG_PARAMS** structure is used to get or set parameters for Internet Key Exchange version 2 (IKEv2) devices ([RFC 4306](https://www.ietf.org/rfc/rfc4306.txt)).

## Members

### `dwNumPorts`

A value that specifies the number of ports configured on the RRAS server to accept IKEv2 connections.

### `dwPortFlags`

A value that specifies the type of ports configured on the RRAS server for IKEv2. The following values are supported:

| Value | Meaning |
| --- | --- |
| **MPR_ENABLE_RAS_ON_DEVICE** | Remote Access is enabled for IKEv2. |

### `dwTunnelConfigParamFlags`

A value that specifies if the user is able to set the tunnel configuration parameters. The following values are supported:

| Value | Meaning |
| --- | --- |
| **MPRAPI_IKEV2_SET_TUNNEL_CONFIG_PARAMS**<br><br>0x01 | If set, the **dwNumPorts**, **dwPortFlags**, and **TunnelConfigParams** fields are valid. |

### `TunnelConfigParams`

An [IKEV2_TUNNEL_CONFIG_PARAMS](https://learn.microsoft.com/windows/desktop/RRAS/router-management-data-types) structure that contains IKEv2 tunnel information.

## See also

[MPRAPI_TUNNEL_CONFIG_PARAMS](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mprapi_tunnel_config_params0)

[Router Management Reference](https://learn.microsoft.com/windows/desktop/RRAS/router-management-reference)

[Router Management Structures](https://learn.microsoft.com/windows/desktop/RRAS/router-management-structures)