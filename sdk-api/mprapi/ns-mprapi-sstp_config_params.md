# SSTP_CONFIG_PARAMS structure

## Description

The **SSTP_CONFIG_PARAMS** structure is used to get and set the device configuration for Secure Socket Tunneling Protocol (SSTP) on a RAS Server.

## Members

### `dwNumPorts`

A value that specifies the number of ports configured on the RRAS server to accept SSTP connections. The maximum values for **dwNumPorts** are listed in the following table. The value zero is not allowed.

| Value | Meaning |
| --- | --- |
| 1 | Windows Web Server 2008 |
| 1000 | Windows Server 2008 Standard |
| 30000 | Windows Server 2008 Datacenter and Windows Server 2008 Enterprise |

**Note** If **dwNumPorts** contains a value beyond the limit configured in the registry at service start time (the default is 1000 for Windows Server 2008 Standard and Windows Server 2008 Enterprise), the [MprConfigServerGetInfoEx](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigservergetinfoex) and [MprConfigServerSetInfoEx](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigserversetinfoex) functions will return **ERROR_SUCCESS_REBOOT_REQUIRED**.

### `dwPortFlags`

A value that specifies the type of ports configured on the RRAS server for SSTP. The following values are supported:

| Value | Meaning |
| --- | --- |
| **MPR_ENABLE_RAS_ON_DEVICE** | If set, RAS is enabled on the device. |

### `isUseHttps`

A value that is **TRUE** if HTTPS is used and **FALSE** otherwise.

### `certAlgorithm`

A value that specifies the certificate hashing algorithm used. The following values are supported:

| Value | Meaning |
| --- | --- |
| **CALG_SHA_256** | 256-bit SHA hashing algorithm |

### `sstpCertDetails`

An [SSTP_CERT_INFO](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-sstp_cert_info) structure that contains the SSTP based certificate hash.

## See also

[MPRAPI_TUNNEL_CONFIG_PARAMS](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mprapi_tunnel_config_params0)

[Router Management Reference](https://learn.microsoft.com/windows/desktop/RRAS/router-management-reference)

[Router Management Structures](https://learn.microsoft.com/windows/desktop/RRAS/router-management-structures)