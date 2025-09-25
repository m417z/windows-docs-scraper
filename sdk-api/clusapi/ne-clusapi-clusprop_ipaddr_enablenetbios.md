# CLUSPROP_IPADDR_ENABLENETBIOS enumeration

## Description

When used with the [CLUSPROP_DWORD](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa368375(v=vs.85)) structure,
enables or disables the functionality of the
[EnableNetBIOS](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/ip-addresses-enablenetbios) property of
[IP Address](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/ip-address) [resources](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources).

## Constants

### `CLUSPROP_IPADDR_ENABLENETBIOS_DISABLED:0`

Disable the functionality of the
[EnableNetBIOS](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/ip-addresses-enablenetbios) property.

### `CLUSPROP_IPADDR_ENABLENETBIOS_ENABLED`

Enable the functionality of the
[EnableNetBIOS](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/ip-addresses-enablenetbios) property.

### `CLUSPROP_IPADDR_ENABLENETBIOS_TRACK_NIC`

Enable the functionality of the
[EnableNetBIOS](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/ip-addresses-enablenetbios) property if the NIC to
which the IP Address resource is bound has enabled NetBIOS.

## See also

[EnableNetBIOS](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/ip-addresses-enablenetbios)

[Failover Cluster Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-enumerations)