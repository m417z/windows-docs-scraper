# PNRP_RESOLVE_CRITERIA enumeration

## Description

The **PNRP_RESOLVE_CRITERIA** enumeration specifies the criteria that PNRP uses to resolve searches.

## Constants

### `PNRP_RESOLVE_CRITERIA_DEFAULT:0`

Use the PNRP_RESOLVE_CRITERIA_NON_CURRENT_PROCESS_PEER_NAME criteria. This is also the default behavior if [PNRPINFO](https://learn.microsoft.com/windows/desktop/api/pnrpns/ns-pnrpns-pnrpinfo_v1) is not specified.

### `PNRP_RESOLVE_CRITERIA_REMOTE_PEER_NAME:1`

Match a peer name. The resolve request excludes any peer name registered locally on this computer.

### `PNRP_RESOLVE_CRITERIA_NEAREST_REMOTE_PEER_NAME:2`

Match a peer name by finding the name with a service location closest to the supplied hint, or if no hint is supplied, closest to the local IP address. The resolve request excludes any peer name registered locally on this computer.

### `PNRP_RESOLVE_CRITERIA_NON_CURRENT_PROCESS_PEER_NAME:3`

Match a peer name. The matching peer name can be registered locally or remotely, but the resolve request excludes any peer name registered by the process making the resolve request.

### `PNRP_RESOLVE_CRITERIA_NEAREST_NON_CURRENT_PROCESS_PEER_NAME:4`

Match a peer name by finding the name with a service location closest to the supplied hint, or if no hint is supplied, closest to the local IP address. The matching peer name can be registered locally or remotely, but the resolve request excludes any peer name registered by the process making the resolve request.

### `PNRP_RESOLVE_CRITERIA_ANY_PEER_NAME:5`

Match a peer name. The matching peer name can be registered locally or remotely.

### `PNRP_RESOLVE_CRITERIA_NEAREST_PEER_NAME`

Match a peer name by finding the name with a service location closest to the supplied hint, or if no hint is supplied, closest to the local IP address. The matching peer name can be registered locally or remotely.

## See also

[PNRPINFO](https://learn.microsoft.com/windows/desktop/api/pnrpns/ns-pnrpns-pnrpinfo_v1)

[PNRP_and WSALookupServiceBegin](https://learn.microsoft.com/windows/desktop/P2PSdk/pnrp-and-wsalookupservicebegin)