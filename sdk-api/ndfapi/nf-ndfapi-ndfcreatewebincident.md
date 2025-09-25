# NdfCreateWebIncident function

## Description

The **NdfCreateWebIncident** function diagnoses web connectivity problems concerning a specific URL.

## Parameters

### `url` [in]

Type: **LPCWSTR**

The URL with which there is a connectivity issue.

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
| **NDF_E_BAD_PARAM** | One or more parameters are invalid. |