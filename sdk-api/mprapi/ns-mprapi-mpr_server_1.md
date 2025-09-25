# MPR_SERVER_1 structure

## Description

The **MPR_SERVER_1** structure is used to retrieve and set the number of ports available for the Point-to-Point Tunneling Protocol (PPTP) and Layer 2 Tunneling Protocol (L2TP) on a device.

## Members

### `dwNumPptpPorts`

Specifies the number of ports configured for PPTP on the device.
The maximum values for *dwNumPptpPorts* are listed in the following table. The value zero is not allowed.

| Maximum Value | Windows Version |
| --- | --- |
| 1 | Windows Server 2003, Web Edition |
| 1000 | Windows Server 2003, Standard Edition |
| 16,384 | Windows Server 2003, Datacenter Edition and Windows Server 2003, Enterprise Edition |

If *dwNumPptpPorts* contains a value beyond the limit configured in the registry at service start time (the default is 1000 for Windows Server 2003, Standard Edition and Windows Server 2003, Enterprise Edition), the [MprConfigServerSetInfo](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigserversetinfo) and [MprAdminServerSetInfo](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminserversetinfo) functions will return **ERROR_SUCCESS_REBOOT_REQUIRED**.

### `dwPptpPortFlags`

A set of bitflags that indicate if RAS or Routing is enabled on the device.

| Value | Meaning |
| --- | --- |
| **MPR_ENABLE_RAS_ON_DEVICE** | If set, RAS is enabled on the device. |
| **MPR_ENABLE_ROUTING_ON_DEVICE** | If set, Routing is enabled on the device. |

### `dwNumL2tpPorts`

Specifies the number of ports configured for L2TP on the device.
The maximum values for *dwNumL2tpPorts* are listed in the following table. The value zero is not allowed.

| Maximum Value | Windows Version |
| --- | --- |
| 1 | Windows Server 2003, Web Edition |
| 1000 | Windows Server 2003, Standard Edition |
| 30,000 | Windows Server 2003, Datacenter Edition and Windows Server 2003, Enterprise Edition |

If *dwNumL2tpPorts* contains a value beyond the limit configured in the registry at service start time (the default is 1000 for Windows Server 2003, Standard Edition and Windows Server 2003, Enterprise Edition), the [MprConfigServerSetInfo](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigserversetinfo) and [MprAdminServerSetInfo](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminserversetinfo) functions will return **ERROR_SUCCESS_REBOOT_REQUIRED**.

### `dwL2tpPortFlags`

A set of bitflags that indicate if RAS or Routing is enabled on the device.

| Value | Meaning |
| --- | --- |
| **MPR_ENABLE_RAS_ON_DEVICE** | If set, RAS is enabled on the device. |
| **MPR_ENABLE_ROUTING_ON_DEVICE** | If set, Routing is enabled on the device. |

## See also

[MPR_SERVER_0](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_server_0)

[MPR_SERVER_2](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_server_2)

[MprAdminServerGetInfo](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminservergetinfo)

[MprAdminServerSetInfo](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminserversetinfo)

[MprConfigServerGetInfo](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigservergetinfo)

[MprConfigServerSetInfo](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigserversetinfo)

[Router Management Reference](https://learn.microsoft.com/windows/desktop/RRAS/router-management-reference)

[Router Management Structures](https://learn.microsoft.com/windows/desktop/RRAS/router-management-structures)