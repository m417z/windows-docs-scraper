# InitializeIpForwardEntry function

## Description

The
**InitializeIpForwardEntry** function initializes a **MIB_IPFORWARD_ROW2** structure with default values for an IP route entry on the local computer.

## Parameters

### `Row` [out]

On entry, a pointer to a
[MIB_IPFORWARD_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipforward_row2) structure entry for an IP route entry. On return, the **MIB_IPFORWARD_ROW2** structure pointed to by this parameter is initialized with default values for an IP route entry.

## Return value

This function does not return a value.

## Remarks

The **InitializeIpForwardEntry** function is defined on Windows Vista and later.

The **InitializeIpForwardEntry** function must be used to initialize the members of a
[MIB_IPFORWARD_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipforward_row2) structure entry with default values for an IP route entry for later use with the [CreateIpForwardEntry2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-createipforwardentry2) function.

On input, **InitializeIpForwardEntry** must be passed a new [MIB_IPFORWARD_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipforward_row2) structure to initialize.

On output, the **ValidLifetime** and **PreferredLifetime** members of the [MIB_IPFORWARD_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipforward_row2) structure pointed to by *Row* parameter will be initialized to infinite and the **Loopback**, **AutoconfigureAddress**, **Publish**, and **Immortal** members will be initialized to **TRUE**. In addition, the **SitePrefixLength**, **Metric**, and **Protocol** members are set to an illegal value and other fields are initialized to zero.

After calling **InitializeIpForwardEntry**, an application can then change the
members in the [MIB_IPFORWARD_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipforward_row2) entry it wishes to modify, and then call the [CreateIpForwardEntry2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-createipforwardentry2) to add the new IP route entry to the local computer.

## See also

[CreateIpForwardEntry2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-createipforwardentry2)

[DeleteIpForwardEntry2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-deleteipforwardentry2)

[GetBestRoute2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getbestroute2)

[GetIpForwardEntry2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getipforwardentry2)

[GetIpForwardTable2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getipforwardtable2)

[MIB_IPFORWARD_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipforward_row2)

[MIB_IPFORWARD_TABLE2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipforward_table2)

[NotifyRouteChange2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-notifyroutechange2)

[SetIpForwardEntry2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-setipforwardentry2)