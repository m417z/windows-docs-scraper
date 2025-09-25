# NETLOGON_INFO_4 structure

## Description

The **NETLOGON_INFO_4** structure defines a level-4 control query response from a domain controller.

## Members

### `netlog4_trusted_dc_name.string`

### `netlog4_trusted_domain_name.string`

### `netlog4_trusted_dc_name`

A marshaled pointer to a string that contains the trusted domain controller name.

### `netlog4_trusted_domain_name`

A marshaled pointer to a string that contains the trusted domain name.

## See also

[I_NetLogonControl2](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-i_netlogoncontrol2)