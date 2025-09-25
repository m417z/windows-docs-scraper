# PEER_APPLICATION_REGISTRATION_TYPE enumeration

## Description

The **PEER_APPLICATION_REGISTRATION_TYPE** enumeration defines the set of peer application registration flags.

## Constants

### `PEER_APPLICATION_CURRENT_USER:0`

The application is available only to the current user account logged into the machine.

### `PEER_APPLICATION_ALL_USERS:1`

The application is available to all user accounts set on the machine.

## Remarks

"Peer application" defines the set of software applications or components available for use with the peer collaboration network. The peer collaboration network enables participants in the network to initiate usage of this application.

Applications with the same GUID and registered for the **current user** take precedence over applications with that same GUID registered for **all users**.

## See also

[Collaboration API Enumerations](https://learn.microsoft.com/windows/desktop/P2PSdk/collaboration-api-enumerations)