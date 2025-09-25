# DRT_REGISTRATION_STATE enumeration

## Description

The **DRT_REGISTRATION_STATE** enumeration defines the set of legal states for a registered key.

## Constants

### `DRT_REGISTRATION_STATE_UNRESOLVEABLE:1`

The locally registered key is no longer resolvable by other nodes. The Distributed Routing Table signals this state when the local security provider is unable to generate an authentication token for the locally registered key.

For example, if the Derived Key Security Provider is used, this state is signaled when the certificate used to authenticate expires.