# NLM_CONNECTIVITY enumeration

## Description

The NLM_Connectivity enumeration is a set of flags that provide notification whenever connectivity related parameters have changed.

## Constants

### `NLM_CONNECTIVITY_DISCONNECTED:0`

The underlying network interfaces have no connectivity to any network.

### `NLM_CONNECTIVITY_IPV4_NOTRAFFIC:0x1`

There is connectivity to a network, but the service cannot detect any IPv4 Network Traffic.

### `NLM_CONNECTIVITY_IPV6_NOTRAFFIC:0x2`

There is connectivity to a network, but the service cannot detect any IPv6 Network Traffic.

### `NLM_CONNECTIVITY_IPV4_SUBNET:0x10`

There is connectivity to the local subnet using the IPv4 protocol.

### `NLM_CONNECTIVITY_IPV4_LOCALNETWORK:0x20`

There is connectivity to a routed network using the IPv4 protocol.

### `NLM_CONNECTIVITY_IPV4_INTERNET:0x40`

There is connectivity to the Internet using the IPv4 protocol.

### `NLM_CONNECTIVITY_IPV6_SUBNET:0x100`

There is connectivity to the local subnet using the IPv6 protocol.

### `NLM_CONNECTIVITY_IPV6_LOCALNETWORK:0x200`

There is connectivity to a local network using the IPv6 protocol.

### `NLM_CONNECTIVITY_IPV6_INTERNET:0x400`

There is connectivity to the Internet using the IPv6 protocol.