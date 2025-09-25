# NdfCreateNetConnectionIncident function

## Description

The **NdfCreateNetConnectionIncident** function diagnoses connectivity issues using the NetConnection helper class.

## Parameters

### `handle` [out]

Type: **NDFHANDLE***

Handle to the Network Diagnostics Framework incident.

### `id`

Type: **GUID**

Identifier of the network interface that the caller would like to create the incident for.

The NULL GUID {00000000-0000-0000-0000-000000000000} may be used if the caller does not want to specify an interface. The system will attempt to determine the most appropriate interface based on the current state of the system.

## Return value

Type: **HRESULT**

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation succeeded. |
| **E_ABORT** | The underlying diagnosis or repair operation has been canceled. |
| **E_OUTOFMEMORY** | There is not enough memory available to complete this operation. |
| **NDF_E_BAD_PARAM** | The handle is invalid. |