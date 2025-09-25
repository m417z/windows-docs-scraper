# NLM_DOMAIN_TYPE enumeration

## Description

The NLM_DOMAIN_TYPE enumeration is a set of flags that specify the domain type of a network.

## Constants

### `NLM_DOMAIN_TYPE_NON_DOMAIN_NETWORK:0`

The Network is not an Active Directory Network.

### `NLM_DOMAIN_TYPE_DOMAIN_NETWORK:0x1`

The Network is an Active Directory Network, but this machine is not authenticated against it.

### `NLM_DOMAIN_TYPE_DOMAIN_AUTHENTICATED:0x2`

The Network is an Active Directory Network, and this machine is authenticated against it.