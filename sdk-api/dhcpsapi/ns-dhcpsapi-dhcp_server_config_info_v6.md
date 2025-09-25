# DHCP_SERVER_CONFIG_INFO_V6 structure

## Description

The **DHCP_SERVER_CONFIG_INFO_V6** structure contains the settings for the DHCPv6 server.

## Members

### `UnicastFlag`

Reserved. This must to be set to 0.

### `RapidCommitFlag`

Reserved. This must to be set to 0.

### `PreferredLifetime`

Integer value that specifies the preferred lifetime for IANA addresses.

### `ValidLifetime`

Integer value that specifies the valid lifetime for IANA addresses.

### `T1`

Integer that specifies the value for time T1.

### `T2`

Integer that specifies the value for time T2.

### `PreferredLifetimeIATA`

The preferred lifetime value for a temporary IPv6 address. This is not used, and must to be set to 0.

### `ValidLifetimeIATA`

The valid lifetime value for a temporary IPv6 address. This is not used, and must to be set to 0.

### `fAuditLog`

If **TRUE**, audit logs are enabled on the DHCPv6 server; if **FALSE**, they are not.