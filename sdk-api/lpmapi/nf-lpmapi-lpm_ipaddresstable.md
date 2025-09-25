# LPM_IpAddressTable function

## Description

The
*LPM_IpAddressTable* function is used by the PCM to pass a list of IP addresses assigned to the Windows 2000 Server upon which the LPM is initialized. The PCM calls this routine after the LPM has successfully initialized, but before making any requests. The PCM also uses the
*LPM_IpAddressTable* function to update LPMs regarding IP address changes. LPMs are expected to detect IP address changes and update their states appropriately.

## Parameters

### `cIpAddrTable` [in]

Number of addresses in the IP table.

### `pIpAddrTable` [in]

Pointer to an
[LPMIPTABLE](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-lpmiptable) structure that contains the IP addresses assigned to the Windows 2000 Server on which the LPM resides.

## Return value

Returns **TRUE** if successful, or **FALSE** otherwise.

## See also

[LPMIPTABLE](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-lpmiptable)