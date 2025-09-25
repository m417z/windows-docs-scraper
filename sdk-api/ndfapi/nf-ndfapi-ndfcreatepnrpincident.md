# NdfCreatePnrpIncident function

## Description

The **NdfCreatePnrpIncident** function creates a session to diagnose issues with the Peer Name Resolution Protocol (PNRP) service.

## Parameters

### `cloudname` [in]

Type: **LPCWSTR**

The name of the cloud to be diagnosed.

### `peername` [in, optional]

Type: **LPCWSTR**

Optional name of a peer node which PNRP can attempt to resolve. The results will be used to help diagnose any problems.

### `diagnosePublish` [in]

Type: **BOOL**

Specifies whether the helper class should verify that the node can publish IDs. If **FALSE**, this diagnostic step will be skipped.

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

The level of diagnosis performed depends on the parameters supplied. The availability of the PNRP service and the availability of the IPv6 networking class will be diagnosed, and additional diagnosis will be performed if certain parameters are supplied.

* If *peername* is specified, NDF will validate the availability of that peer in the PNRP network.
* If *diagnosePublish* is specified, NDF will validate the ability to publish a name in PNRP.