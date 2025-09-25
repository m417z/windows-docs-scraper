# NdfCreateInboundIncident function

## Description

The **NdfCreateInboundIncident** function creates a session to diagnose inbound connectivity for a specific application or service.

## Parameters

### `applicationID` [in, optional]

Type: **LPCWSTR**

The fully qualified path to the application receiving the inbound traffic.

### `serviceID` [in, optional]

Type: **LPCWSTR**

The Windows service receiving the inbound traffic.

##### dll,-28502 (File/Print Sharing)

##### dll,-28752 (Remote Desktop)

##### dll,-32752 (Network Discovery)

### `userID` [in, optional]

Type: **SID***

The SID for the application receiving the traffic. If **NULL**, the caller's SID is automatically used.

### `localTarget` [in, optional]

Type: **const [SOCKADDR_STORAGE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms740504(v=vs.85))**

A [SOCKADDR_STORAGE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms740504(v=vs.85)) structure which limits the diagnosis to traffic to a specific IP address. If **NULL**, all traffic will be included in the diagnosis.

### `protocol`

Type: **IPPROTO**

The protocol which should be diagnosed. For example, IPPROTO_TCP would be used to indicate the TCP/IP protocol.

### `dwFlags`

Type: **DWORD**

Possible values:

**NDF_INBOUND_FLAG_EDGETRAVERSAL**

Indicates that a configuration should be considered unhealthy if both gateways on the local network are within the private access range, rather than only considering the configuration to be healthy if both gateways are Internet Gateway Devices (IGDs).

**NDF_INBOUND_FLAG_HEALTHCHECK**

Ends the session immediately if no inbound traffic problems are diagnosed, instead of turning on detailed tracing and allowing the user to reproduce their problem for a second diagnosis.

### `handle` [out]

Type: **NDFHANDLE***

Pointer to a handle to the Network Diagnostics Framework incident.

## Return value

Type: **HRESULT**

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation succeeded. |
| **E_INVALIDARG** | One or more parameters has not been provided correctly. |

## Remarks

Either *applicationID* or *serviceID* must be specified, but not both.