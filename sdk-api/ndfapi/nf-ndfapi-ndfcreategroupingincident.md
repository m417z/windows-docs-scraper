# NdfCreateGroupingIncident function

## Description

The **NdfCreateGroupingIncident** function creates a session to diagnose peer-to-peer grouping functionality issues.

## Parameters

### `CloudName` [in, optional]

Type: **LPCWSTR**

The name of the Peer Name Resolution Protocol (PNRP) cloud where the group is created. If **NULL**, the session will not attempt to diagnose issues related to PNRP.

### `GroupName` [in, optional]

Type: **LPCWSTR**

The name of the group to be diagnosed. If **NULL**, the session will not attempt to diagnose issues related to group availability.

### `Identity` [in, optional]

Type: **LPCWSTR**

The identity that a peer uses to access the group. If **NULL**, the session will not attempt to diagnose issues related to the group's ability to register in PNRP.

### `Invitation` [in, optional]

Type: **LPCWSTR**

An XML invitation granted by another peer. An invitation is created when the inviting peer calls [PeerGroupCreateInvitation](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupcreateinvitation) or [PeerGroupIssueCredentials](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupissuecredentials). If this value is present, the invitation will be checked to ensure its format and expiration are valid.

### `Addresses` [in, optional]

Type: **SOCKET_ADDRESS_LIST***

Optional list of addresses of the peers to which the application is trying to connect. If this parameter is used, the helper class will diagnose connectivity to these addresses.

### `appId` [in, optional]

Type: **LPCWSTR**

Application ID for the calling application.

### `handle` [out]

Type: **NDFHANDLE***

Handle to the Network Diagnostics Framework incident.

## Return value

Type: **HRESULT**

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation succeeded. |
| **NDF_E_BAD_PARAM** | One or more parameters has not been provided correctly. |

## Remarks

The level of diagnosis performed depends on the parameters supplied.

* If no parameters are specified, NDF will validate the grouping service status, the status of peer-to-peer services (PNRP and Identity Manager), and Windows clock synchronization.
* If *CloudName* is specified, NDF will validate grouping functionality in that cloud.
* If *GroupName* is specified, NDF will validate that the name can be resolved in PNRP (or invoke the PNRP helper class if the name cannot be resolved) and validate the firewall settings for grouping.
* If *Identity* is specified, NDF will validate PNRP's ability to register the *GroupName* with this Identity. If this fails, the PNRP helper class will be invoked.
* If *Invitation* is specified, the *GroupName* will be derived from the Invitation (if a *GroupName* was not also specified) and NDF will validate the invitation's format and status.
* If *Addresses* is specified, NDF will validate whether Windows can connect to up to three of these addresses.