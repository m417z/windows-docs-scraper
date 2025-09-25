# DOT11_ADHOC_CONNECT_FAIL_REASON enumeration

## Description

Specifies the reason why a connection attempt failed.

## Constants

### `DOT11_ADHOC_CONNECT_FAIL_DOMAIN_MISMATCH`

The local host's configuration is incompatible with the target network. This occurs when the local host is 802.11d compliant and the regulatory domain of the local host is not compatible with the regulatory domain of the target network. For more information about regulatory domains, see the IEEE 802.11d-2001 standard. The standard can be downloaded from the [IEEE website](https://standards.ieee.org/standard).

### `DOT11_ADHOC_CONNECT_FAIL_PASSPHRASE_MISMATCH`

The passphrase supplied to authenticate the local machine or user on the target network is incorrect.

### `DOT11_ADHOC_CONNECT_FAIL_OTHER`

The connection failed for another reason.