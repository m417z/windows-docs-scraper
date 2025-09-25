# NLM_NETWORK_CATEGORY enumeration

## Description

The NLM_NETWORK_CATEGORY enumeration is a set of flags that specify the category type of a network.

## Constants

### `NLM_NETWORK_CATEGORY_PUBLIC:0`

The network is a public (untrusted) network.

### `NLM_NETWORK_CATEGORY_PRIVATE:0x1`

The network is a private (trusted) network.

### `NLM_NETWORK_CATEGORY_DOMAIN_AUTHENTICATED:0x2`

The network is authenticated against an Active Directory domain.

## Remarks

The private or public network categories must never be used to assume which Windows Firewall ports are open, as the user can change the default settings of these categories. Instead, Firewall APIs should be called to ensure the ports that the required ports are open.