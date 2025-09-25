# IKEEXT_CERT_CONFIG_TYPE enumeration

## Description

The **IKEEXT_CERT_CONFIG_TYPE** enumerated type indicates a type of certificate configuration.

## Constants

### `IKEEXT_CERT_CONFIG_EXPLICIT_TRUST_LIST:0`

An explicit trust list will be used for authentication.

### `IKEEXT_CERT_CONFIG_ENTERPRISE_STORE`

The enterprise store will be used as the trust list for authentication.

### `IKEEXT_CERT_CONFIG_TRUSTED_ROOT_STORE`

The trusted root CA store will be used as the trust list for authentication.

### `IKEEXT_CERT_CONFIG_UNSPECIFIED`

No certificate authentication in the direction (inbound or outbound) specified by the configuration.

Available only on Windows 7, Windows Server 2008 R2, and later.

### `IKEEXT_CERT_CONFIG_TYPE_MAX`

Maximum value for testing purposes.

## See also

[Windows Filtering Platform API Enumerated Types](https://learn.microsoft.com/windows/desktop/FWP/fwp-enums)