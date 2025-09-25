# DhcpDsCleanup function

## Description

The **DhcpDsCleanup** function frees up directory service resources allocated for DHCP services by [DhcpDsInit](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpdsinit). This function should be called exactly once for each corresponding DHCP service process, and only when the process is terminated.

## See also

[DhcpDsInit](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpdsinit)