## Description

The **SecPkgCredentials_KdcNetworkSettingsW** structure is used to configure network settings for Kerberos Key Distribution Center (KDC) communications in secure environments. It is typically used in scenarios where specific network configurations are required for secure communication with KDCs.

## Members

### `Version`

Specifies the version of the network settings structure. For this structure, it should be set to **KDC_NETWORK_SETTINGS_V2**.

### `Flags`

Specifies flags that dictate the behavior of the network settings. Valid flags include:

| Flag | Description |
| ---- | ----------- |
| KDC_NETWORK_SETTINGS_FLAGS_FORCEPROXY (0x1) | Forces the use of a proxy for KDC communications. |
| KDC_NETWORK_SETTINGS_FLAGS_CONFIGURE_PROXY (0x80000000) | Indicates that proxy configuration is required. |
| KDC_NETWORK_SETTINGS_FLAGS_CONFIGURE_DISCOVERY (0x40000000) | Indicates that domain controller discovery configuration is required. |

### `ProxyServerOffset`

Offset, in bytes, from the beginning of the structure to the proxy server string. This field is optional.

### `ProxyServerLength`

Length, in bytes, of the proxy server string.

### `ClientTlsCredOffset`

Offset, in bytes, from the beginning of the structure to the client TLS credentials. This field is optional.

### `ClientTlsCredLength`

Length, in bytes, of the client TLS credentials.

### `DcDiscoveryFlags`

Flags related to domain controller discovery. Valid flags include:

| Flag | Description |
| ---- | ----------- |
| KDC_NETWORK_DISCOVERY_FLAGS_DS13_REQUIRED (0x80000000) | Indicates that DS 1.3 discovery is required. |