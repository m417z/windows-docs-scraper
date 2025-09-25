# NETCONNECTINFOSTRUCT structure

## Description

The **NETCONNECTINFOSTRUCT** structure contains information about the performance of a network. It is used by the
[NPGetConnectionPerformance](https://learn.microsoft.com/windows/desktop/api/npapi/nf-npapi-npgetconnectionperformance) function.

## Members

### `cbStructure`

The size of the **NETCONNECTINFOSTRUCT** structure, in bytes. This is filled in by the caller to indicate the size of the structure passed in. The network provider should leave this field unchanged and can assume that the structure is large enough to contain all fields up to and including **dwOptDataSize**.

### `dwFlags`

This is a bitmask which may have one or more of the following flags.

| Value | Meaning |
| --- | --- |
| **WNCON_FORNETCARD** | If set, the information returned is for the performance of the netcard used for the connection. This information is returned if information about the actual connection is not available. <br><br>If not set, the information returned is for the current connection with the resource, with any routing degradation taken into consideration. |
| **WNCON_NOTROUTED** | If set, the connection is not treated as being routed. In other words, routing is not taken into account when estimating the performance. This means actual performance may be much less than the information returned. <br><br>If not set, the connection may be going through routers that limit performance. |
| **WNCON_SLOWLINK** | If set, the connection is known at some point to be over a medium that is typically slow (for example, a modem using a normal quality phone line). <br><br>Providers that return a value in **dwSpeed** do not have to set this bit. |
| **WNCON_DYNAMIC** | If set, some of the information returned is dynamically recalculated. If that is the case, reissuing this request on the connection may return different, more current, information. |

### `dwSpeed`

The speed of the media to the network resource in units of 100bps. For example, a 1,200 baud point-to-point link returns 12.

### `dwDelay`

The delay introduced by the network when sending information, in milliseconds. In other words, the time between when the network starts to send data and the time it is received. This is in addition to any latency that was incorporated into the calculation of **dwSpeed**, so the value returned will be zero for accessing most resources.

### `dwOptDataSize`

A recommendation for the size of data, in bytes, that is most efficiently sent through the network when an application makes a single request to the network resource. For example, for a disk network resource, this value might be 2048 or 512 when writing a block of data.