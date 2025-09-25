# MPRAPI_TUNNEL_CONFIG_PARAMS0 structure

## Description

The **MPRAPI_TUNNEL_CONFIG_PARAMS** structure is used to get or set configuration of tunnel parameters on a RAS Server.

## Members

### `IkeConfigParams`

A [IKEV2_CONFIG_PARAMS](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ikev2_config_params) structure that contains Internet Key Exchange version 2 (IKEv2) tunnel parameters.

### `PptpConfigParams`

A [PPTP_CONFIG_PARAMS](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-pptp_config_params) structure that contains Point-to-Point Tunneling Protocol (PPTP) tunnel parameters.

### `L2tpConfigParams`

A [L2TP_CONFIG_PARAMS](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-l2tp_config_params0) structure that contains Layer 2 Tunneling Protocol (L2TP) tunnel parameters.

### `SstpConfigParams`

A [SSTP_CONFIG_PARAMS](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-sstp_config_params) structure that contains Secure Socket Tunneling Protocol (SSTP) tunnel parameters.

## See also

[MPR_SERVER_SET_CONFIG_EX](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_server_set_config_ex0)

[Router Management Enumerated Types](https://learn.microsoft.com/windows/desktop/RRAS/router-management-enumerations)

[Router Management Reference](https://learn.microsoft.com/windows/desktop/RRAS/router-management-reference)