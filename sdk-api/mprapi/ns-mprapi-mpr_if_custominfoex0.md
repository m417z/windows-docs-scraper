# MPR_IF_CUSTOMINFOEX0 structure

## Description

Gets or sets tunnel specific custom configuration for a demand dial interfaces.

Do not use the **MPR_IF_CUSTOMINFOEX0** structure directly in your code; using [MPR_IF_CUSTOMINFOEX](https://learn.microsoft.com/windows/desktop/RRAS/router-management-data-types) instead ensures that the proper version, based on the operating system the code in compiled under, is used.

## Members

### `Header`

A [MPRAPI_OBJECT_HEADER](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mprapi_object_header) structure that specifies the version of the **MPR_IF_CUSTOMINFOEX0** structure.

### `dwFlags`

A value that specifies the tunnel type for which the custom configuration is available. The following values are supported.

| Value | Meaning |
| --- | --- |
| 0x0 | No custom configuration available. |
| **MPRAPI_IF_CUSTOM_CONFIG_FOR_IKEV2**<br><br>0x1 | IKEv2 tunnel specific configuration is available. |

### `customIkev2Config`

A [ROUTER_IKEv2_IF_CUSTOM_CONFIG0](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-router_ikev2_if_custom_config0) structure that specifies the IKEv2 tunnel configuration parameters.

## See also

[MprAdminInterfaceGetCustomInfoEx](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfacegetcustominfoex)

[MprAdminInterfaceSetCustomInfoEx](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfacesetcustominfoex)

[MprConfigInterfaceGetCustomInfoEx](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfiginterfacegetcustominfoex)

[MprConfigInterfaceSetCustomInfoEx](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfiginterfacesetcustominfoex)