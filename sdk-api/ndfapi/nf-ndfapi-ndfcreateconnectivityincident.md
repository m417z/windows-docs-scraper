# NdfCreateConnectivityIncident function

## Description

The **NdfCreateConnectivityIncident** function diagnoses generic Internet connectivity problems.

## Parameters

### `handle` [out]

Type: **NDFHANDLE***

Handle to the Network Diagnostics Framework incident.

## Return value

Type: **HRESULT**

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation succeeded. |
| **E_ABORT** | The underlying diagnosis or repair operation has been canceled. |
| **E_OUTOFMEMORY** | There is not enough memory available to complete this operation. |
| **NDF_E_BAD_PARAM** | The handle is invalid. |