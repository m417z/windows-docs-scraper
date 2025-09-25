# CLUS_NETNAME_IP_INFO_FOR_MULTICHANNEL structure

## Description

Represents IP information for a NetName resource that has Multichannel enabled.

## Members

### `szName`

An array of wide characters that specifies the name of the resource.

### `NumEntries`

The number of channels that are specified by the *IpInfo* parameter.

### `IpInfo`

An array of [CLUS_NETNAME_IP_INFO_ENTRY](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clus_netname_ip_info_entry) structures that specify the IP info for each channel.

## See also

[Utility structures](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/utility-structures)