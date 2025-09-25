# ISOLATION_STATE enumeration

## Description

Defines the set of possible isolation state values of a machine. The isolation state of a machine determines its network connectivity.

## Constants

### `ISOLATION_STATE_UNKNOWN:0`

The client's access to the network is unknown.

### `ISOLATION_STATE_NOT_RESTRICTED:1`

The client has unrestricted full access to the network.

### `ISOLATION_STATE_IN_PROBATION:2`

The client has probationary access to the network for a limited amount of time during which time they must fix their system.

### `ISOLATION_STATE_RESTRICTED_ACCESS:3`

The client has restricted access to the network; the client is allowed access to some servers only from which they can obtain necessary information and patches to update themselves to become healthy.

### `v1_enum`

## Remarks

Network Access Protection (NAP) uses the **ISOLATION_STATE** value to determine if a client should be granted network access.

## See also

[EAPHost Supplicant Enumerations](https://learn.microsoft.com/windows/win32/eaphost/eap-host-supplicant-enumerations)

[Implementing In-Band NAP Support for EAP Methods](https://learn.microsoft.com/windows/win32/eaphost/enabling-in-band-nap-support)

[Implementing NAP Support for EAP Methods](https://learn.microsoft.com/windows/win32/eaphost/implementing-nap-for-eap-methods)

[NAP IsolationState](https://learn.microsoft.com/windows/desktop/api/naptypes/ne-naptypes-isolationstate)

[NotificationHandler](https://learn.microsoft.com/windows/desktop/api/eappapis/nc-eappapis-notificationhandler)